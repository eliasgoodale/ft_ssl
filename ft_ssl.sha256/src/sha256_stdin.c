/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:55:42 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/14 09:34:50 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	sha256_stdin(void)
{
	t_vector	v;
	int			ret;
	char		buf[BUFF_SIZE];

	g_flags |= STDINREAD;
	if (ft_vector_init(&v, BUFF_SIZE) == -1)
		return ;
	while ((ret = read(STDIN_FILENO, buf, BUFF_SIZE)))
		ft_vector_nappend(&v, buf, ret);
	sha256_string(v.data);
	g_flags -= STDINREAD;
	ft_vector_free(&v);
}
