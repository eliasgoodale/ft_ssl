/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:34:45 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/27 13:24:51 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

uintmax_t		ft_bitinsert(uintmax_t nb, uintmax_t ins, unsigned lb, unsigned ub)
{
	VAR(uintmax_t, all_ones, ~0);
	VAR(uintmax_t, left, all_ones << (ub + 1));
	VAR(uintmax_t, right, ((1 << lb) - 1));
	VAR(uintmax_t, mask, (left | right));
	VAR(uintmax_t, nb_cleared, nb & mask);
	VAR(uintmax_t, m_shifted, ins << lb);
	return(nb_cleared | m_shifted);
}
