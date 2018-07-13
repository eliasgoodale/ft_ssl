/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 20:20:45 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/12 16:15:08 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void md5_memcpy (unsigned char *output, unsigned char *input, size_t len)
{
	VAR(unsigned, i, -1);
  	while(++i < len)
 		output[i] = input[i];
}

void md5_memset(unsigned char *output, int c, size_t len)
{
  unsigned int i;

  for (i = 0; i < len; i++)
 ((char *)output)[i] = (char)c;
}

void	rotate_back(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d)
{
	uint32_t	tmp;

	tmp = *a;
	*a = *d;
	*d = *c;
	*c = *b;
	*b = tmp;
}