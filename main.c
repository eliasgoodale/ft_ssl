/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:35:22 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 22:25:05 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char g_flags = 0;

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		VAR(int, hash_ftype, 1);
		if (ft_strcmp("md5", av[hash_ftype]) == 0)
			generate_md5((ac - 1), (av + 1));
		else if (ft_strcmp("sha256", av[hash_ftype]) == 0)
			generate_sha256((ac - 1), (av + 1));
		else
			ft_printf("Argument %s is invalid. usage:\
			./ft_ssl<md5/sha256> <flags/args>", av[hash_ftype]);
	}
	else
		ft_printf("Usage: ./ft_ssl <md5/sha256> <flags/args>");
}
