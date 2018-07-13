/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 18:25:00 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 13:01:09 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "../include/sha256_hash.h"

void    modulate_fifth(uint32_t o[8], uint32_t tone1, uint32_t tone2)
{
    o[7] = o[6];
    o[6] = o[5];
    o[5] = o[4];
    o[4] = o[3] + tone1;
    o[3] = o[2];
    o[2] = o[1];
    o[1] = o[0];
    o[0] = tone1 + tone2;
}

void    sha256_hash(uint32_t W[64], uint32_t m[8])
{
    VAR(uint32_t, tone1, 0);
    VAR(uint32_t, tone2, 0);
    VAR(unsigned, i, 0);
    while(i < 64)
    {
        tone1 = m[7] + BSIG1(m[4]) + CH(m[4], m[5], m[6]) + K[i] + W[i];
        tone2 = BSIG0(m[0]) + MAJ(m[0], m[1], m[2]);
        modulate_fifth(m, tone1, tone2);
        i++;
    }
}

void    sha256_encode(uint32_t output[64], uint8_t input[64], unsigned len)
{
    VAR(unsigned, i, 0);
    VAR(unsigned, i4, i);
    while (i < 16)
    {
        output[i] = ((((uint32_t)input[i4]) << 24) |
                (((uint32_t)input[i4 + 1]) << 16) |
                (((uint32_t)input[i4 + 2]) << 8) |
                (((uint32_t)input[i4 + 3])));
        i++;
        i4 += 4;
    }
    while(i < len)
    {
        output[i] =  SSIG1(output[i - 2]) + output[i - 7] +
                SSIG0(output[i - 15]) + output[i - 16];
        i++;
    }
}


void    sha256_process_message(t_sha256_ctx *ctx)
{
    uint32_t    W[64];
    uint32_t    mstate[8];
    int i;
    
    
    sha256_encode(W, ctx->message_block, 64);
    i = -1;
    while(++i < 8)
        mstate[i] = ctx->state[i];
    sha256_hash(W, mstate);
    i = -1;
    while (++i < 8)
        ctx->state[i] += mstate[i];
    ctx->message_block_index = 0;
}
