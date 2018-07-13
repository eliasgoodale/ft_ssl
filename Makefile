# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 19:20:37 by egoodale          #+#    #+#              #
#    Updated: 2018/07/13 13:39:30 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

MD5_SRC =		ft_ssl.md5/src/md5_digest.c ft_ssl.md5/src/md5_encode.c ft_ssl.md5/src/md5_hash.c\
				ft_ssl.md5/src/md5_file.c ft_ssl.md5/src/md5_mem.c ft_ssl.md5/src/md5_string.c\
				ft_ssl.md5/src/md5_parse.c ft_ssl.md5/src/md5_stdin.c
MD5_OBJ = $(addprefix obj/, $(MD5_SRC:.c=.o))

SHA256_SRC =	ft_ssl.sha256/src/sha256_digest.c ft_ssl.sha256/src/sha256_hash.c ft_ssl.sha256/src/sha256_helper.c\
				ft_ssl.sha256/src/sha256_parse.c ft_ssl.sha256/src/sha256_string.c ft_ssl.sha256/src/sha256_file.c
SHA256_OBJ = $(addprefix obj/, $(SHA256_SRC:.c=.o)) 
HDR = ft_ssl.h
LIBFT_A = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g
MAIN_DRIVER = main.c
all: $(NAME)

$(NAME): $(MD5_SRC) $(SHA256_SRC) $(LIBFT_A)
	$(CC) -I $(HDR) $(CFLAGS) $(MD5_SRC) $(SHA256_SRC) $(MAIN_DRIVER) -o $(NAME) $(LIBFT_A)
	