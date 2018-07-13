/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:35:22 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/12 16:15:08 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

#define EXISTS_BEFORE(a, b) ((a && !b) || (a && b && a < b) ? 1 : 0)

char	parse_flags(char *flag_s)
{
	VAR(char, flags, 0);
	VAR(char *, s_loc, ft_strchr(flag_s, 's'));
	VAR(char *, p_loc, ft_strchr(flag_s, 'p'));
	VAR(char *, q_loc, ft_strchr(flag_s, 'q'));
	VAR(char *, r_loc, ft_strchr(flag_s, 'r'));
	if (EXISTS_BEFORE(p_loc, s_loc))
		md5_stdin();
	if (EXISTS_BEFORE(q_loc, s_loc))
		flags |= QUIET;
	if (EXISTS_BEFORE(r_loc, s_loc))
		flags |= REVERSE;
	if (s_loc)
		md5_string(s_loc + 1);
	return (flags);
}

int		parse_string_args(int ac, char **av, int arg)
{
	while(++arg < (ac - 1) && av[arg][0] == '-' && av[arg][1] == 's')
	{
		if (ft_strcmp(av[arg], "-s") == 0)
		{
			if(arg != ac - 1)
				md5_string(av[++arg]);
			else
			{
				ft_printf("ft_ssl: md5: option requires an argument -- s\n");
				exit(0);
			}
		}
		else if(av[arg][0] == '-' && av[arg][1] == 's')
			md5_string(&av[arg][2]);
	}
	return (arg);

}

int		parse_file_args(int ac, char **av, int arg)
{
	VAR(char, flags, 0);
	if (av[arg][0] == '-')
		flags = parse_flags(av[arg++]);
	while(arg < ac)
		md5_file(av[arg++], flags);
	return (arg);
}

void	md5_parse_args(int ac, char **av)
{
	VAR(int, arg, 0);
	arg = parse_string_args(ac, av, arg);
	arg = parse_file_args(ac, av, arg);
	
}


int generate_md5(int ac, char **av)
{
	if (ac > 1)
	{
		md5_parse_args(ac, av);
	}
	else
		md5_stdin();
	return 0;
}





































