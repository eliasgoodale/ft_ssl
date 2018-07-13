/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:18:30 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/13 13:37:45 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ssl.h"

void    sha256_file_print(uint8_t digest[32], char *filename, char flags)
{
    if (flags & QUIET)
        sha256_print(digest);
    else if (flags & REVERSE)
    {
        sha256_print(digest);
        ft_printf(" %s", filename);
    }
    else
    {
        ft_printf("MD5 (%s) = ");
        sha256_print(digest);
    }
    ft_printf("\n");
}

void    sha256_file(char *filename, char flags)
{
    int             fd;
    unsigned char   buf[BUFF_SIZE];
    uint8_t         digest[32];
    t_sha256_ctx    ctx;
    int             ret;

    ft_bzero(digest, 32);
    if((fd = open(filename, O_RDONLY)) > 0)
    {
        sha256_init_ctx(&ctx);
        while((ret = read(fd, buf, BUFF_SIZE)))
            sha256_input(&ctx, (uint8_t *)buf, (uint_least64_t) ret);
        sha256_result(&ctx, digest);
        sha256_file_print(digest, filename, flags);
    }
    else
        ft_printf("ft_ssl: sha256: No such file or directory\n");
    
}