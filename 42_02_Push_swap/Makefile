# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 14:24:07 by benjamsc          #+#    #+#              #
#    Updated: 2025/01/13 15:01:19 by benjamsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -O3
NAME = push_swap
NAME_BONUS = checker
SRCS = srcs/count_moove.c srcs/list_manipulation.c srcs/list_utils.c srcs/other.c srcs/push_swap.c srcs/push_swap_init.c srcs/push_swap_op.c srcs/push_swap_op_ult.c srcs/push_swap_parsing.c srcs/struct_help.c srcs/sort_utils.c srcs/sort_list.c srcs/getter_utils.c
SRCS_BONUS = srcs/op_bonus.c srcs/op_ult_bonus.c srcs/struct_help_bonus.c srcs/list_manipulation_bonus.c srcs/checker_bonus.c srcs/list_utils_bonus.c srcs/init_bonus.c srcs/parser_bonus.c srcs/other_bonus.c
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
LIB_PATH = -Llibft
LIB_NAME = -lft 
INCLUDE_PATH = -Ilibft/includes -Iincludes


all: LIBFT $(NAME)
bonus: LIBFT $(NAME_BONUS)

LIBFT:
	@cd libft >> /dev/null && make >> /dev/null && cd .. >> /dev/null
%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)
$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME_BONUS)
clean:
	rm -rf **/*.o libft/srcs/*.o
clean_bonus:
	rm -rf **/*_bonus.o
fclean: clean clean_bonus
	rm -rf $(NAME) libft/libft.a $(NAME_BONUS) checker_linux 
re : fclean all

listC:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' ';
listB:
	@find -wholename "./srcs/*_bonus.c" | cut -c 3- | tr '\n' ' ';

CHECKER:
	@if [ ! -f "checker_linux" ]; then \
		echo "\033[0;33mDownloading and chmod checker...\033[0m"; \
		wget https://cdn.intra.42.fr/document/document/28291/checker_linux >> /dev/null; \
		chmod +x checker_linux; \
		echo "\033[0;32mChecker downloaded\033[0m"; \
	else \
		echo "\033[0;32mChecker already downloadedd\033[0m"; \
	fi

.PHONY: random test
test:
	@tmp=$$(seq -10000 10000 | shuf -n $(word 2, $(MAKECMDGOALS)) | tr '\n' ' '); >> /dev/null \
    echo $$tmp >> out.log; \
    ./push_swap $$tmp

random:
	@(seq -10000 10000 | shuf -n $(word 2, $(MAKECMDGOALS)) | tr '\n' ' ');

%:
	@:

