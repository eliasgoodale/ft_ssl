/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:10:43 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/27 13:25:11 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_printbits(uintmax_t nb)
{
	VAR(uintmax_t, i, (1ULL << 63));
	VAR(unsigned, pos, get_msb(nb));
	VAR(unsigned, is_first, 1);
	if (nb == 0)
	{
		write(1, "0b0", 3);
		return ;
	}
	while(i)
	{
		if (i <= pos)
		{
			ft_putchar('0' + ((i & nb) && 1));
			if (is_first)
			{
				ft_putchar('b');
				is_first = 0;
			}
		}
		i >>= 1;
	}
}