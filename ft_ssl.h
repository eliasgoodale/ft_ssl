/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:38:41 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/14 09:54:21 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_SSL_H
#	define FT_SSL_H

#include <stdint.h>
#include <fcntl.h>
#include <libft.h>
#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_ssl.md5/include/md5.h"
#include "ft_ssl.sha256/include/sha256.h"

#define BUFF_SIZE 10
#define EXISTS_BEFORE(a, b) ((a && !b) || (a && b && a < b) ? 1 : 0)

enum		e_flag_set {
	QUIET = (1 << 0),
	REVERSE = (1 << 1),
	STDINREAD = (1 << 2)
};
extern char	g_flags;

#	endif
