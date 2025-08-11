CC = cc
FLAGS = -Wall -Wextra -Werror
FLAGS_SA = -fsanitize=thread
NAME = philo
SRCS = srcs/getters.c srcs/main.c srcs/routines_utils.c srcs/obs.c srcs/check.c srcs/func_checker.c srcs/destroy.c srcs/routines.c
OBJ = $(SRCS:.c=.o)
LIB_NAME = -lpthread
INCLUDE_PATH = -Iincludes

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE_PATH) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

s: fclean
	$(foreach src, $(SRCS), $(CC) $(FLAGS) $(FLAGS_SA) $(INCLUDE_PATH) -c $(src) -o $(src:.c=.o);)
	$(CC) $(FLAGS) $(FLAGS_SA) $(OBJ) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)

listC:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' '
