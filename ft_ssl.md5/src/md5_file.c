/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:25:27 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 21:24:10 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void	md5_print(unsigned char digest[16], char *input)
{
	if (g_flags & QUIET)
		md5_print_digest(digest);
	else if (g_flags & REVERSE)
	{
		md5_print_digest(digest);
		ft_printf(" %s", input);
	}
	else
	{
		ft_printf("MD5 (%s) = ", input);
		md5_print_digest(digest);
	}
	ft_printf("\n");
}

void	md5_file(char *filename)
{
	int				fd;
	unsigned char	buf[BUFF_SIZE];
	unsigned char	digest[16];
	t_md5_ctx		ctx;
	int				ret;

	ft_bzero(digest, 16);
	if ((fd = open(filename, O_RDONLY)) > 0)
	{
		md5_init_ctx(&ctx);
		while ((ret = read(fd, buf, BUFF_SIZE)))
			md5_update(&ctx, buf, ret);
		md5_final(digest, &ctx);
		md5_print(digest, filename);
	}
	else
		ft_printf("ft_ssl: md5: No such file or directory\n");
}
