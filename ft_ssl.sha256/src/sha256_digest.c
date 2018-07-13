/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_digest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:18:45 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 11:43:42 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"


int     sha256_result(t_sha256_ctx *ctx, uint8_t digest[32])
{
    VAR(int, i, -1);
    if (!ctx || !digest)
        return (_NULL);
    if (ctx->corrupted)
        return(ctx->corrupted);
    if (!ctx->computed)
        sha256_finalize(ctx, 0x80);
    while (++i < 32)
        digest[i] = (uint8_t)(ctx->state[i >> 2] >> 8 * (3 - (i & 0x03)));
    return (SUCCESS);
}

void    sha256_finalize(t_sha256_ctx *ctx, uint8_t pad_bits)
{
  sha256_pad_message(ctx, pad_bits);
  ft_bzero((void *)ctx->message_block, MSG_BLK_SZ);
  ctx->len_high = 0;
  ctx->len_low = 0;
  ctx->computed = 1;
}

/*
int     sha256_final_bits(t_sha256_ctx *ctx, uint8_t bits, unsigned len)
{
    uint8_t masks[8];
    uint8_t marks[8];

    generate_final_params(masks, marks);
    if (!ctx)
        return (_NULL);
    if (!len)
        return (SUCCESS);
    if (ctx->corrupted)
        return (ctx->corrupted);
    if (ctx->computed)
        return (ctx->corrupted = ESTATE);
    if (len > 7)
        return (ctx->corrupted = EBADPARAM);
    sha256_add_length(ctx, len);
    sha256_finalize(ctx, (uint8_t)((bits & masks[len]) | marks[len]));
    return (ctx->corrupted);


}
*/
int     sha256_input(t_sha256_ctx *ctx, uint8_t *input, uint_least64_t len)
{
    if (!ctx || !input)
        return (_NULL);
    if (!len)
        return (SUCCESS);
    if (ctx->computed)
        return ((ctx->corrupted = ESTATE));
    if (ctx->corrupted)
        return (ctx->corrupted);
    while (len--)
    {
        ctx->message_block[ctx->message_block_index++] = *input;
        if ((sha256_add_length(ctx, 8) == SUCCESS) && (ctx->message_block_index == MSG_BLK_SZ))
            sha256_process_message(ctx);
        input++;
    }
    return (ctx->corrupted);
}