CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCC = srcs/ft_abs.c srcs/ft_atoi.c srcs/ft_atol.c srcs/ft_bool_array.c srcs/ft_boolarray_manip.c srcs/ft_booltab_manip.c srcs/ft_bzero.c srcs/ft_calloc.c srcs/ft_check.c srcs/ft_cut.c srcs/ft_dups.c srcs/ft_fprintf.c srcs/ft_free_fullstrs.c srcs/ft_free_strs.c srcs/ft_intlen.c srcs/ft_isalnum.c srcs/ft_isalpha.c srcs/ft_isascii.c srcs/ft_isdigit.c srcs/ft_isprime.c srcs/ft_isprint.c srcs/ft_isspace.c srcs/ft_iswhitespace.c srcs/ft_itoa.c srcs/ft_lstadd_back.c srcs/ft_lstadd_front.c srcs/ft_lstclear.c srcs/ft_lstdelone.c srcs/ft_lstiter.c srcs/ft_lstlast.c srcs/ft_lstmap.c srcs/ft_lstnew.c srcs/ft_lstsize.c srcs/ft_ltoa.c srcs/ft_memchr.c srcs/ft_memcmp.c srcs/ft_memcpy.c srcs/ft_memmove.c srcs/ft_memset.c srcs/ft_min_max.c srcs/ft_print_bits.c srcs/ft_print_strs.c srcs/ft_printf.c srcs/ft_putchar_fd.c srcs/ft_putchar_pf.c srcs/ft_putchar_pfd.c srcs/ft_putendl_fd.c srcs/ft_putnbr_fd.c srcs/ft_putnbr_pf.c srcs/ft_putnbr_pfd.c srcs/ft_putstr_fd.c srcs/ft_range.c srcs/ft_reverse_bits.c srcs/ft_rrange.c srcs/ft_split.c srcs/ft_str_add_char.c srcs/ft_strcasestr.c srcs/ft_strchr.c srcs/ft_strcmp.c srcs/ft_strcmp_safe.c srcs/ft_strdup.c srcs/ft_striteri.c srcs/ft_strjoin.c srcs/ft_strlcat.c srcs/ft_strlcpy.c srcs/ft_strldup.c srcs/ft_strlen.c srcs/ft_strmapi.c srcs/ft_strncmp.c srcs/ft_strnstr.c srcs/ft_strrchr.c srcs/ft_strrev.c srcs/ft_strsdup.c srcs/ft_strslen.c srcs/ft_strstr.c srcs/ft_strtrim.c srcs/ft_substr.c srcs/ft_swap_bits.c srcs/ft_tolower.c srcs/ft_toupper.c srcs/ft_unsplit.c srcs/ft_utoa.c srcs/ft_xlen.c srcs/ft_xtoa.c srcs/get_next_line.c srcs/get_next_line_free.c srcs/get_next_line_utils.c srcs/ft_str_strs_len.c
OBJ = $(SRCC:.c=.o)
NAME = libft.a
INCLUDE = includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

listC:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' '
listNb:
	@find -wholename "./srcs/*.c" | wc -l
.PHONY: all clean fclean re bonus compL


