CC = cc
FLAGS = -Wall -Wextra -Werror -g3
NAME_SERV = server
NAME_SERV_BONUS = server_b
NAME_CLIENT = client
NAME_CLIENT_BONUS = client_b
SRCS = srcs/server.c srcs/client.c srcs/common.c
SRCS_BONUS = srcs/server_bonus.c srcs/client_bonus.c srcs/common_bonus.c
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
LIB_PATH = -Llibft
LIB_NAME = -lft 
INCLUDE_PATH = -Ilibft/includes -Iincludes

all: LIBFT $(NAME_SERV) $(NAME_CLIENT)

bonus: LIBFT $(NAME_SERV_BONUS) $(NAME_CLIENT_BONUS)

LIBFT:
	@cd libft >> /dev/null && make >> /dev/null && cd .. >> /dev/null
%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -O3 -c $< -o $@
$(NAME_SERV): $(OBJ)
	$(CC) $(FLAGS) srcs/server.o srcs/common.o $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME_SERV)
$(NAME_CLIENT): $(OBJ)
	$(CC) $(FLAGS) srcs/client.o srcs/common.o $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME_CLIENT)
$(NAME_SERV_BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) srcs/server_bonus.o srcs/common_bonus.o $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME_SERV_BONUS)
$(NAME_CLIENT_BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) srcs/client_bonus.o srcs/common_bonus.o $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME_CLIENT_BONUS)
clean:
	rm -rf *.o ./srcs/*/*.o libft/srcs/*.o srcs/*.o
fclean: clean
	rm -rf $(NAME_SERV) $(NAME_CLIENT) libft/libft.a $(NAME_SERV_BONUS) $(NAME_CLIENT_BONUS)
re : fclean all

listC:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' '
