# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 14:24:07 by benjamsc          #+#    #+#              #
#    Updated: 2025/01/08 18:23:28 by benjamsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = srcs/main.c srcs/draw/draw.c srcs/draw/draw_utils.c srcs/draw/colors_utils.c srcs/errors.c srcs/free/free_utils.c srcs/free/frees.c srcs/free/free_img.c srcs/moove.c srcs/check.c srcs/win_management.c srcs/enemy.c srcs/data/enemy_data.c srcs/data/map_data.c srcs/data/player_data.c srcs/data/get_data.c srcs/map/get_map.c srcs/map/check_map.c srcs/map/check_map_utils.c srcs/map/map_management.c srcs/utils.c
OBJ = $(SRCS:.c=.o)
LIB_PATH = -Lmlx_linux -Llibft -L/usr/lib
LIB_NAME = -lmlx_Linux -lft -lXext -lX11 -lm -lz 
INCLUDE_PATH = -I/usr/include -Imlx_linux -Ilibft/includes -Iincludes

all: MLX LIBFT $(NAME)

DL_MLX:
	@if [ ! -d "mlx_linux" ]; then \
        echo "Downloading and extracting minilibx..."; \
        wget https://cdn.intra.42.fr/document/document/34997/minilibx-linux.tgz >> /dev/null; \
        tar -xf minilibx-linux.tgz; \
        mv minilibx-linux mlx_linux; \
    else \
        echo "mlx-linux already downloaded."; \
    fi

MLX: DL_MLX
	@make -C mlx_linux > /dev/null 2>&1

LIBFT:
	@cd libft >> /dev/null && make && cd .. >> /dev/null
%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE_PATH) -O3 -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $(NAME)
clean_mlx:
	$(MAKE) -C libft clean > /dev/null 2>&1
	rm -rf minilibx-linux.tgz
clean: clean_mlx
	rm -rf *.o ./sources/*.o libft/srcs/*.o srcs/*.o
fclean_mlx: clean_mlx
	rm -rf mlx_linux
fclean: clean
	rm -rf $(NAME) libft/libft.a
aclean: fclean_mlx fclean
re : fclean all

listC:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' '
listNb:
	@find -wholename "./srcs/*.c" | wc -l
