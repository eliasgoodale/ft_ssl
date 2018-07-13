
NAME = libft.a
HDR = include/libft.h
OBJ_DIR = ./obj/

GNL_DIR = ./get_next_line/
GNL_HDR = include/get_next_line.h
GNL_SRC = get_next_line.c
GNL_OBJ = get_next_line.o
GNL_OBJ_DIR = ./obj/gnl_obj/

FT_PRINTF_DIR = ./ft_printf/
FT_PRINTF_HDR = include/ft_printf.h
FT_PRINTF_SRC = check_mods.c \
				ft_printf.c \
				handle_chr.c \
				handle_msc.c \
				handle_signed.c \
				handle_strings.c \
				handle_unsigned.c \
				parse_args.c \
				parse_precision.c \
				parse_unsigned.c
FT_PRINTF_OBJ = $(patsubst %.c, %.o, $(FT_PRINTF_SRC))
PRINTF_OBJ_DIR = ./obj/printf_obj

FT_BIT_DIR = ./ft_bits/
FT_BIT_SRC =	ft_bitinsert.c \
				ft_printbits.c \
				get_msb.c
FT_BIT_OBJ = $(patsubst %.c, %.o, $(FT_BIT_SRC))
BIT_OBJ_DIR = ./obj/bit_obj/

FT_CHR_DIR = ./ft_chr/
FT_CHR_SRC =    ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_wchrlen.c
FT_CHR_OBJ = $(patsubst %.c, %.o, $(FT_CHR_SRC))
CHR_OBJ_DIR = ./obj/chr_obj/

FT_CONV_DIR = ./ft_conv/
FT_CONV_SRC =   ft_imaxtoa.c \
				ft_itoa.c \
				ft_uimaxtoa_base.c
FT_CONV_OBJ = $(patsubst %.c, %.o, $(FT_CONV_SRC))
CONV_OBJ_DIR = ./obj/conv_obj/

FT_INT_DIR = ./ft_int/
FT_INT_SRC =    ft_intlen.c \
				ft_max.c \
				ft_uintlen.c
FT_INT_OBJ = $(patsubst %.c, %.o, $(FT_INT_SRC))
INT_OBJ_DIR = ./obj/int_obj/

FT_LST_DIR = ./ft_lst/
FT_LST_SRC =    ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstpushback.c \
				ft_lstpushfront.c
FT_LST_OBJ = $(patsubst %.c, %.o, $(FT_LST_SRC))
LST_OBJ_DIR = ./obj/lst_obj/

FT_STR_DIR = ./ft_str/
FT_STR_SRC =    ft_atoi.c\
				ft_insert_str.c\
				ft_sortwords.c\
				ft_str_is_alpha.c\
				ft_str_is_lowercase.c\
				ft_str_is_numeric.c\
				ft_str_is_printable.c\
				ft_str_is_uppercase.c\
				ft_str_toupper.c\
				ft_strcat.c\
				ft_str_to_unicode.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_strfill.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strlowcase.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strndup.c\
				ft_strnequ.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_strzchr.c\
				ft_vector.c\
				ft_wordcount.c\
				ft_wstr_to_str.c\
				ft_wstrdup.c\
				ft_wstrlen.c
FT_STR_OBJ = $(patsubst %.c, %.o, $(FT_STR_SRC))
STR_OBJ_DIR = ./obj/str_obj/

FT_MEM_DIR = ./ft_mem/
FT_MEM_SRC =    ft_bzero.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_realloc.c \
				ft_recalloc.c
FT_MEM_OBJ = $(patsubst %.c, %.o, $(FT_MEM_SRC))
MEM_OBJ_DIR = ./obj/mem_obj/

FT_WRITE_DIR = ./ft_write/
FT_WRITE_SRC =  ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putnbr_unsigned.c \
				ft_putnchar.c \
				ft_putstr.c \
				ft_putstr_fd.c
FT_WRITE_OBJ = $(patsubst %.c, %.o, $(FT_WRITE_SRC))
WRITE_OBJ_DIR = ./obj/write_obj/

COMPILED =  $(FT_CHR_OBJ) $(FT_CONV_OBJ) $(FT_INT_OBJ) \
			$(FT_LST_OBJ) $(FT_STR_OBJ) $(FT_MEM_OBJ) \
			$(FT_WRITE_OBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ) \
			$(FT_BIT_OBJ)

OBJ_DIRS = $(CHR_OBJ_DIR) $(CONV_OBJ_DIR) $(INT_OBJ_DIR) \
			$(LST_OBJ_DIR) $(STR_OBJ_DIR) $(MEM_OBJ_DIR) \
			$(WRITE_OBJ_DIR) $(OBJ_DIR) $(PRINTF_OBJ_DIR)\
			$(GNL_OBJ_DIR) $(BIT_OBJ_DIR)
all: $(NAME) obj_cleanup

obj_cleanup: $(NAME) $(OBJ_DIRS)
	@mv $(FT_BIT_OBJ) $(BIT_OBJ_DIR)
	@mv $(FT_CHR_OBJ) $(CHR_OBJ_DIR)
	@mv $(FT_CONV_OBJ) $(CONV_OBJ_DIR)
	@mv $(FT_INT_OBJ) $(INT_OBJ_DIR)
	@mv $(FT_LST_OBJ) $(LST_OBJ_DIR)
	@mv $(FT_STR_OBJ) $(STR_OBJ_DIR)
	@mv $(FT_MEM_OBJ) $(MEM_OBJ_DIR)
	@mv $(FT_WRITE_OBJ) $(WRITE_OBJ_DIR)
	@mv $(FT_PRINTF_OBJ) $(PRINTF_OBJ_DIR)
	@mv $(GNL_OBJ) $(GNL_OBJ_DIR)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(FT_PRINTF_OBJ): %.o: $(FT_PRINTF_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_PRINTF_DIR) -I $(HDR) -I $(FT_PRINTF_HDR) $< -o $@
$(GNL_OBJ): %.o: $(GNL_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(GNL_DIR) -I $(HDR) -I $(GNL_HDR) $< -o $@
$(FT_BIT_OBJ): %.o: $(FT_BIT_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_BIT_DIR) -I $(HDR) $< -o $@
$(FT_CHR_OBJ): %.o: $(FT_CHR_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_CHR_DIR) -I $(HDR) $< -o $@
$(FT_CONV_OBJ): %.o: $(FT_CONV_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_CONV_DIR) -I $(HDR) $< -o $@
$(FT_INT_OBJ): %.o: $(FT_INT_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_INT_DIR) -I $(HDR) $< -o $@
$(FT_LST_OBJ): %.o: $(FT_LST_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_LST_DIR) -I $(HDR) $< -o $@
$(FT_STR_OBJ): %.o: $(FT_STR_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_STR_DIR) -I $(HDR) $< -o $@
$(FT_MEM_OBJ): %.o: $(FT_MEM_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_MEM_DIR) -I $(HDR) $< -o $@
$(FT_WRITE_OBJ): %.o: $(FT_WRITE_DIR)%.c
	@$(CC) -c $(CFLAGS) -I $(FT_WRITE_DIR) -I $(HDR) $< -o $@

$(COMPILED): | $(OBJ_DIRS)

$(GNL_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(GNL_OBJ_DIR)
$(PRINTF_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(PRINTF_OBJ_DIR)
$(BIT_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(BIT_OBJ_DIR)
$(CHR_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(CHR_OBJ_DIR)
$(CONV_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(CONV_OBJ_DIR)
$(INT_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(INT_OBJ_DIR)
$(LST_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(LST_OBJ_DIR)
$(STR_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(STR_OBJ_DIR)
$(MEM_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(MEM_OBJ_DIR)
$(WRITE_OBJ_DIR): $(OBJ_DIR)
	@mkdir $(WRITE_OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:	
	@rm -rf $(OBJ_DIR)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
	
