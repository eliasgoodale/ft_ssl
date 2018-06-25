# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 19:20:37 by egoodale          #+#    #+#              #
#    Updated: 2018/06/19 09:53:07 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

MD5_SRC += md5/md5_digest.c md5/md5_encode.c md5/md5_hash.c
MD5_SRC	+=	md5/md5_mem.c md5/md5_string.c md5/main.c
MD5_OBJ = $(addprefix obj/, $(MD5_SRC:.c=.o))
MD5_HDR = inc/
LIBFT_A = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(MD5_SRC) $(LIBFT_A)
	$(CC) -I $(MD5_HDR) $(CFLAGS) $(MD5_SRC) -o $(NAME) $(LIBFT_A)










#NAME = ft_ssl
#CFLAGS = -Wall -Werror -Wextra 
#INC_DIR = ./inc/
#OBJ_DIR = ./obj/
#SSL_HDR = $(INC_DIR)ft_ssl.h
#LIBFT_A = libft/libft.a 
#
#MD5_SRC_DIR = ./md5_src/
#MD5_HDR = $(INC_DIR)md5.h
#
#
#MD5_OBJ_DIR = $(OBJ_DIR)md5_obj/
#											#SHA_SRC_DIR = ./sha_src/
#											#SHA_HDR = $(HDR)sha256.h
#											#SHA_SRC = 
#											#SHA_OBJ = $(patsubst %.c, %.o, $(SHA_SRC))
#											#SHA_OBJ_DIR = $(OBJ_DIR)sha_obj/
#SSL_OBJ_DIR = $(MD5_OBJ_DIR) 				#$(SHA_OBJ_DIR)
#COMPILED = $(MD5_OBJ) 						#$(SHA_OBJ)
#$(MD5_OBJ_DIR): $(OBJ_DIR)
#	@mkdir $(MD5_OBJ_DIR)
#$(OBJ_DIR):
#	@mkdir $(OBJ_DIR)
#all: $(NAME) $(MD5_OBJ_DIR)
#	@mv $(MD5_OBJ) $(MD5_OBJ_DIR)
#											#@mv $(SHA_OBJ) $(SHA_OBJ_DIR)
#$(NAME): $(COMPILED)
#	@$(CC) -g $(CFLAGS) -o $(NAME) $(COMPILED) $(LIBFT_A)
#
#$(MD5_OBJ): %.o: $(MD5_SRC_DIR)%.c
#	@$(CC) -g -c $(CFLAGS) -I $(MD5_SRC_DIR) -I $(MD5_HDR) $< -o $@
#
#											#$(SHA_OBJ): %.o: $(SHA_SRC_DIR)%.c
#											#	@$(CC) -c $(CFLAGS) -I $(SHA_SRC_DIR) -I $(SSL_HDR) -I $(SHA_HDR) $< -o $@
#
#clean:
#	rm -rf $(OBJ_DIR)
#fclean: clean
#	rm -rf $(NAME)
#re: fclean all


		
