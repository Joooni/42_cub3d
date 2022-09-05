# -*- MakeFile -*-

NAME = cub3d
# -*- Compiler -*-
GCC = gcc
FLAGS = -Wall -Wextra -Werror -Imlx

# -*- Includes -*-
SRC_PATH = src/
LIBFT = libft
INCL = incl
MLX_MACOS = mlx

# -*- Source Files -*-
SRC =	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		$(SRC_PATH)controls.c \
		$(SRC_PATH)controls_move.c \
		$(SRC_PATH)draw_minimap.c \
		$(SRC_PATH)draw_utils.c \
		$(SRC_PATH)init.c \
		$(SRC_PATH)init2.c \
		$(SRC_PATH)free.c \
		$(SRC_PATH)utils.c \
		$(SRC_PATH)raycaster.c \
		$(SRC_PATH)map_handler.c \
		$(SRC_PATH)check_map.c \
		$(SRC_PATH)check_map_utils.c \
		$(SRC_PATH)draw_map.c \
		$(SRC_PATH)3drawing.c \
		$(SRC_PATH)textures.c \
		$(SRC_PATH)ft_split_cub3d.c \
		$(SRC_PATH)ft_isvalidchar.c \
		$(SRC_PATH)time.c \
		$(SRC_PATH)check_map2.c \
		$(SRC_PATH)movement.c \


# -*- Objects -*-
SRCS=$(addprefix $(SRC_PATH),$(SRC))

all: lib tmp $(NAME)

tmp:
	@mkdir -p obj

# -*- MacOS -*-
lib:
	make -C $(LIBFT)
	make -C $(MLX_MACOS)

$(NAME): $(LIBFT)/libft.a $(SRC)
	$(GCC) $(OBJ) $(FLAGS) $^ -L $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

debug: $(LIBFT)/libft.a $(SRC)
	$(GCC) $(OBJ) $(FLAGS) $^ -L $(LIBFT) -g3 -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

test:
	make
	./cub3d maps/minimaptest.cub

leaks:
	make
	leaks --fullStacks --atExit -- ./cub3d maps/leaks.cub

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_PATH)

fclean:
	make clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	rm -f libmlx.dylib
	rm -f src/libmlx.dylib


re:	fclean all


.PHONY: temporary, re, fclean, clean