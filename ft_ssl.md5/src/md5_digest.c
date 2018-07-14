/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_digest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:39:12 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 16:00:46 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	init_padding(unsigned char padding[64])
{
	ft_bzero(padding, 64);
	padding[0] = 0x80;
}

void	md5_final(unsigned char digest[16], t_md5_ctx *ctx)
{
	unsigned char	bits[8];
	unsigned		index;
	unsigned		pad_len;
	unsigned char	padding[64];

	init_padding(padding);
	md5_encode(bits, ctx->i, 8);
	index = (unsigned int)((ctx->i[0] >> 3) & 0x3f);
	pad_len = (index < 56) ? (56 - index) : (120 - index);
	md5_update(ctx, padding, pad_len);
	md5_update(ctx, bits, 8);
	md5_encode(digest, ctx->state, 16);
	md5_memset((unsigned char *)ctx, 0, sizeof(*ctx));
}

void	md5_update(t_md5_ctx *ctx, unsigned char *input, size_t input_len)
{
	VAR(unsigned, index, (unsigned)(ctx->i[0] >> 3) & 0x3F);
	VAR(unsigned, part_len, 64 - index);
	VAR(unsigned, i, part_len);
	if ((ctx->i[0] += ((uint32_t)input_len << 3))
	< ((uint32_t)input_len << 3))
		ctx->i[1]++;
	ctx->i[1] += ((uint32_t)input_len >> 29);
	part_len = 64 - index;
	if (input_len >= part_len)
	{
		md5_memcpy(&ctx->in[index], input, part_len);
		md5_transform(ctx->state, ctx->in);
		while ((i + 63) < input_len)
		{
			md5_transform(ctx->state, ctx->in);
			i += 64;
		}
		index = 0;
	}
	else
		i = 0;
	md5_memcpy(&ctx->in[index], (unsigned char *)&input[i], input_len - i);
}
