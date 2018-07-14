/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:55:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 22:15:29 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

int		sha256_add_length(t_sha256_ctx *ctx, unsigned len)
{
	VAR(uint32_t, add_temp, ctx->len_low);
	ctx->corrupted = (((ctx->len_low += len) < add_temp) &&
	((++ctx->len_high) == 0)) ? EINPUTOOLONG : ctx->corrupted;
	return (ctx->corrupted);
}

void	sha256_pad_message(t_sha256_ctx *ctx, uint8_t pad_bits)
{
	if (ctx->message_block_index >= MSG_BLK_SZ - 8)
	{
		ctx->message_block[ctx->message_block_index++] = pad_bits;
		while (ctx->message_block_index < MSG_BLK_SZ)
			ctx->message_block[ctx->message_block_index++] = 0;
		sha256_process_message(ctx);
	}
	else
		ctx->message_block[ctx->message_block_index++] = pad_bits;
	while (ctx->message_block_index < MSG_BLK_SZ - 8)
		ctx->message_block[ctx->message_block_index++] = 0;
	ctx->message_block[56] = (uint8_t)(ctx->len_high >> 24);
	ctx->message_block[57] = (uint8_t)(ctx->len_high >> 16);
	ctx->message_block[58] = (uint8_t)(ctx->len_high >> 8);
	ctx->message_block[59] = (uint8_t)(ctx->len_high);
	ctx->message_block[60] = (uint8_t)(ctx->len_low >> 24);
	ctx->message_block[61] = (uint8_t)(ctx->len_low >> 16);
	ctx->message_block[62] = (uint8_t)(ctx->len_low >> 8);
	ctx->message_block[63] = (uint8_t)(ctx->len_low);
	sha256_process_message(ctx);
}

void	generate_final_params(uint8_t masks[8], uint8_t marks[8])
{
	masks[0] = 0x00;
	masks[1] = 0x80;
	masks[2] = 0xC0;
	masks[3] = 0xE0;
	masks[4] = 0xF0;
	masks[5] = 0xF8;
	masks[6] = 0xFC;
	masks[7] = 0xFE;
	marks[0] = 0x80;
	marks[1] = 0x40;
	marks[2] = 0x20;
	marks[3] = 0x10;
	marks[4] = 0x08;
	marks[5] = 0x04;
	marks[6] = 0x02;
	marks[7] = 0x01;
}
