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
SRC =	main.c

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