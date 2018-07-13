/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:38:00 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/15 19:45:47 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMIX_H
#define BITMIX_H

#define BITMIX_BUILTIN 3

typedef	uint32_t t_bitmix_f(uint32_t, uint32_t, uint32_t);

typedef struct	s_bitmix
{
	char		op;
	t_bitmix_f 	mixer;
}				t_bitmix;

t_bitmix g_mixer_tab[] = {
	{'F', &f_mix},
	{'G', &g_mix},
	{'H', &h_mix}
};

#endif