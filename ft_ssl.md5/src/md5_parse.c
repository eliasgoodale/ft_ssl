/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:39:54 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 22:12:04 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	md5_parse_flags(char *flag_s)
{
	VAR(char *, s_loc, ft_strchr(flag_s, 's'));
	VAR(char *, p_loc, ft_strchr(flag_s, 'p'));
	VAR(char *, q_loc, ft_strchr(flag_s, 'q'));
	VAR(char *, r_loc, ft_strchr(flag_s, 'r'));
	if (EXISTS_BEFORE(p_loc, s_loc))
		md5_stdin();
	if (EXISTS_BEFORE(q_loc, s_loc))
		g_flags |= QUIET;
	if (EXISTS_BEFORE(r_loc, s_loc))
		g_flags |= REVERSE;
	if (s_loc && (s_loc + 1) != NULL)
		md5_string(s_loc + 1);
}

int		md5_parse_string_args(int ac, char **av, int arg)
{
	while (++arg < ac && av[arg][0] == '-')
	{
		if (ft_strcmp(av[arg], "-s") == 0)
		{
			if (arg != ac - 1)
				md5_string(av[++arg]);
			else
			{
				ft_printf("ft_ssl: md5: option requires an argument -- s\n");
				exit(0);
			}
		}
		else if (av[arg][0] == '-' && av[arg][1] == 's')
			md5_string(&av[arg][2]);
		else
			md5_parse_flags(av[arg]);
	}
	return (arg);
}

int		md5_parse_file_args(int ac, char **av, int arg)
{
	while (arg < ac)
	{
		if (av[arg][0] == '-')
			md5_parse_flags(av[arg++]);
		md5_file(av[arg]);
		arg++;
	}
	return (arg);
}

void	md5_parse_args(int ac, char **av)
{
	VAR(int, arg, 0);
	arg = md5_parse_string_args(ac, av, arg);
	if (arg < ac)
		arg = md5_parse_file_args(ac, av, arg);
}

int		generate_md5(int ac, char **av)
{
	if (ac > 1)
		md5_parse_args(ac, av);
	else
		md5_stdin();
	return (SUCCESS);
}
