/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:35:22 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/19 10:52:50 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/md5.h"
void	md5_parse_args(int ac, char **av)
{
	VAR(int, i, 0);
	while(++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == 's')
			md5_string(av[i + 1]);
		else
			exit(0);
	}
}

int main(int ac, char **av)
{
	if (ac > 1)
		md5_parse_args(ac, av);
	return 0;
}