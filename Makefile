# -*- MakeFile -*-

NAME = cub3d
# -*- Compiler -*-
GCC = gcc
FLAGS = -Wall -Wextra -Werror -Imlx -O3

# -*- Includes -*-
SRC_PATH = src/
OBJ_PATH = obj/
LIBFT = libft
INCL = incl
MLX_MACOS = mlx_macos
MLX_LINUX = mlx_linux

# -*- Source Files -*-
SRC =	main.c \
		$(SRC_PATH)

# -*- Objects -*-
SRCS=$(addprefix $(SRC_PATH),$(SRC))
OBJS=$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

all: lib tmp $(NAME)

tmp:
	@mkdir -p obj

# -*- MacOS -*-
lib:
	make -C $(LIBFT)
	make -C $(MLX_MACOS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(GCC) $(FLAGS) -c -o $@ $^

$(NAME): $(OBJS) $(LIBFT)/libft.a
	$(GCC) $(FLAGS) $^ -L $(LIBFT) -lmlx -framework OpenGL -framework AppKit -lz -lm -o $(NAME)
endif

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