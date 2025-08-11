CC = cc
FLAGS = -Wall -Wextra -Werror -g3
S_FLAGS = -fsanitize=address
NAME = minishell
SRCS = srcs/builtin/getter_utils.c srcs/builtin/builtin_utils.c srcs/builtin/directory_func.c srcs/builtin/echo_func.c srcs/builtin/env_func.c srcs/builtin/export_func.c srcs/path_management.c srcs/error_management.c srcs/history.c srcs/main.c srcs/terminal.c srcs/utils.c srcs/exec/pipes_redirections.c srcs/exec/exec.c srcs/exec/exec_utils2.c srcs/exec/command_path_utils.c srcs/exec/pipes.c srcs/exec/exec_utils.c srcs/init_data.c srcs/signal_management.c srcs/redirections/heredoc_utils.c srcs/redirections/output_redirections.c srcs/redirections/infile_redirections.c srcs/redirections/heredoc.c srcs/redirections/redirections_fd_utils.c srcs/init_data_utils.c srcs/lex_2/ft_lex2.c srcs/lex_2/is_arg_ok.c srcs/lex_2/lex_func_utils.c srcs/lex_2/lex_node_utils.c srcs/lex_2/lex_utils.c srcs/lex_2/expandables.c srcs/parsing2/list_utils.c srcs/parsing2/parsing.c srcs/parsing2/parsing_extract.c srcs/parsing2/parsing_redir.c srcs/parsing2/free_list.c srcs/parsing2/check_syntax.c srcs/parsing2/init_list.c srcs/error_management2.c

OBJ = $(SRCS:.c=.o)
LIB_PATH = -Llibft
LIB_NAME = -lft -lreadline
INCLUDE_PATH = -Ilibft/includes -Iincludes
SUPP := $(abspath readline.supp)


all: LIBFT $(NAME)

LIBFT:
	@make all -C libft >> /dev/null && >> /dev/null
%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -c $< -o $@

s: $(OBJ)
	$(CC) $(FLAGS) $(S_FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)
clean:
	rm -rf $(OBJ) libft/srcs/*.o
fclean: clean
	rm -rf $(NAME) libft/libft.a 
re : fclean all

listC:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' ';
listNb:
	@find -wholename "./srcs/*.c" | wc -l
val: re
	valgrind --leak-check=full --track-fds=yes --trace-children=yes --show-leak-kinds=all --suppressions=$(SUPP) ./minishell
