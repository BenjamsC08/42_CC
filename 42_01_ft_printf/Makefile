CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCC = srcs/ft_printf.c srcs/ft_putchar_pf.c srcs/ft_putnbr_pf.c srcs/ft_toa_pf.c srcs/utils_pf.c
OBJ = $(SRCC:.c=.o)
NAME = libftprintf.a
INCLUDE = includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
