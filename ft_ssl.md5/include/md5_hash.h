/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:49:02 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 15:51:35 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MD5_HASH_H
#	define MD5_HASH_H

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

enum	e_rotation_keys
{
	R11 = 7,
	R12 = 12,
	R13 = 17,
	R14 = 22,
	R21 = 5,
	R22 = 9,
	R23 = 14,
	R24 = 20,
	R31 = 4,
	R32 = 11,
	R33 = 16,
	R34 = 23,
	R41 = 6,
	R42 = 10,
	R43 = 15,
	R44 = 21
};

unsigned	g_ffrot_tab[16] = {
	R11, R12, R13, R14, R11, R12, R13, R14,
	R11, R12, R13, R14, R11, R12, R13, R14
};

uint32_t	g_ffhash[16] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821
};

unsigned	g_fforder[16] = {
	0, 1, 2, 3, 4, 5, 6, 7,
	8, 9, 10, 11, 12, 13, 14, 15
};

unsigned	g_ggrot_tab[16] = {
	R21, R22, R23, R24, R21, R22, R23, R24,
	R21, R22, R23, R24, R21, R22, R23, R24
};

uint32_t	g_gghash[16] = {
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x2441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a
};

unsigned	g_ggorder[16] = {
	1, 6, 11, 0, 5, 10, 15, 4,
	9, 14, 3, 8, 13, 2, 7, 12
};

unsigned	g_hhrot_tab[16] = {
	R31, R32, R33, R34, R31, R32, R33, R34,
	R31, R32, R33, R34, R31, R32, R33, R34
};

uint32_t	g_hhhash[16] = {
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x4881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665
};

unsigned	g_hhorder[16] = {
	5, 8, 11, 14, 1, 4, 7, 10,
	13, 0, 3, 6, 9, 12, 15, 2
};

unsigned	g_iirot_tab[16] = {
	R41, R42, R43, R44, R41, R42, R43, R44,
	R41, R42, R43, R44, R41, R42, R43, R44
};

uint32_t	g_iihash[16] = {
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

unsigned	g_iiorder[16] = {
	0, 7, 14, 5, 12, 3, 10, 1,
	8, 15, 6, 13, 4, 11, 2, 9
};

#	endif
