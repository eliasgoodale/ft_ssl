/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_encode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:04:11 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/18 14:50:26 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"

void 		md5_encode(unsigned char *output, uint32_t *input, size_t len)
{
	VAR(unsigned, i, 0);
	VAR(unsigned, j, 0);
	while(j < len)
	{
		output[j] = (unsigned char)(input[i] & 0xff);
		output[j+1] = (unsigned char)((input[i] >> 8) & 0xff);
		output[j+2] = (unsigned char)((input[i] >> 16) & 0xff);
		output[j+3] = (unsigned char)((input[i] >> 24) & 0xff);
		i++;
		j += 4;
	}
}

void		md5_decode(uint32_t *output, unsigned char *input, size_t len)
{
	VAR(unsigned, i, 0);
	VAR(unsigned, j, 0);
	while(j < len)
	{
		output[i] = ((uint32_t)input[j]) | (((uint32_t)input[j+1]) << 8) |
		(((uint32_t)input[j+2]) << 16) | (((uint32_t)input[j+3]) << 24);
		i++;
		j += 4;
	}
}