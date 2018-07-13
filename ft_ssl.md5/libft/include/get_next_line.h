/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:46:43 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/04 12:53:02 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#define BUFF_SIZE 2

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct	s_gnl {
	char		str[BUFF_SIZE + 1];
	int			fd;
	char		*new;
	char		*final;
	char		*tmp;
	char		*src;
	char		save[BUFF_SIZE];
	int			buf_s;
}				t_gnl;

int				get_next_line(int fd, char **line);

#	endif
