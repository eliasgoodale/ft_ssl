/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:44:42 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 13:59:19 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"
#include "../include/md5_hash.h"

static inline void	md5_ff(uint32_t mstate[4], uint32_t x[16])
{
	VAR(unsigned, i, -1);
	while (++i < 16)
	{
		mstate[0] += F(mstate[1], mstate[2], mstate[3]) +
		x[g_fforder[i]] + g_ffhash[i];
		mstate[0] = ROTATE_LEFT(mstate[0], g_ffrot_tab[i]);
		mstate[0] += mstate[1];
		rotate_back(&mstate[0], &mstate[1], &mstate[2], &mstate[3]);
	}
}

static inline void	md5_gg(uint32_t mstate[4], uint32_t x[16])
{
	VAR(unsigned, i, -1);
	while (++i < 16)
	{
		mstate[0] += G(mstate[1], mstate[2], mstate[3]) +
		x[g_ggorder[i]] + g_gghash[i];
		mstate[0] = ROTATE_LEFT(mstate[0], g_ggrot_tab[i]);
		mstate[0] += mstate[1];
		rotate_back(&mstate[0], &mstate[1], &mstate[2], &mstate[3]);
	}
}

static inline void	md5_hh(uint32_t mstate[4], uint32_t x[16])
{
	VAR(unsigned, i, -1);
	while (++i < 16)
	{
		mstate[0] += H(mstate[1], mstate[2], mstate[3]) +
		x[g_hhorder[i]] + g_hhhash[i];
		mstate[0] = ROTATE_LEFT(mstate[0], g_hhrot_tab[i]);
		mstate[0] += mstate[1];
		rotate_back(&mstate[0], &mstate[1], &mstate[2], &mstate[3]);
	}
}

static inline void	md5_ii(uint32_t mstate[4], uint32_t x[16])
{
	VAR(unsigned, i, -1);
	while (++i < 16)
	{
		mstate[0] += I(mstate[1], mstate[2], mstate[3]) +
		x[g_iiorder[i]] + g_iihash[i];
		mstate[0] = ROTATE_LEFT(mstate[0], g_iirot_tab[i]);
		mstate[0] += mstate[1];
		rotate_back(&mstate[0], &mstate[1], &mstate[2], &mstate[3]);
	}
}

void				md5_transform(uint32_t state[4], unsigned char block[64])
{
	uint32_t		x[16];
	uint32_t		mstate[4];

	md5_decode(x, block, 64);
	mstate[0] = state[0];
	mstate[1] = state[1];
	mstate[2] = state[2];
	mstate[3] = state[3];
	md5_ff(mstate, x);
	md5_gg(mstate, x);
	md5_hh(mstate, x);
	md5_ii(mstate, x);
	state[0] += mstate[0];
	state[1] += mstate[1];
	state[2] += mstate[2];
	state[3] += mstate[3];
	md5_memset((unsigned char *)x, 0, sizeof(x));
}
