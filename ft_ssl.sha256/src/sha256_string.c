/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:52:11 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 21:31:45 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	sha256_init_ctx(t_sha256_ctx *ctx)
{
	ctx->len_high = 0;
	ctx->len_low = 0;
	ctx->message_block_index = 0;
	ctx->state[0] = 0x6a09e667;
	ctx->state[1] = 0xbb67ae85;
	ctx->state[2] = 0x3c6ef372;
	ctx->state[3] = 0xa54ff53a;
	ctx->state[4] = 0x510e527f;
	ctx->state[5] = 0x9b05688c;
	ctx->state[6] = 0x1f83d9ab;
	ctx->state[7] = 0x5be0cd19;
	ctx->computed = 0;
	ctx->corrupted = SUCCESS;
}

void	sha256_print_digest(uint8_t digest[32])
{
	VAR(unsigned, i, -1);
	while (++i < 32)
		ft_printf("%02x", digest[i]);
}

void	sha256_string(char *input)
{
	t_sha256_ctx	ctx;
	uint_least64_t	input_len;
	uint8_t			digest[32];

	input_len = ft_strlen(input);
	sha256_init_ctx(&ctx);
	sha256_input(&ctx, (uint8_t *)input, input_len);
	sha256_result(&ctx, digest);
	sha256_print(digest, input);
}
