CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fractol

SRCS = Mandatory/main.c Mandatory/fractals.c Mandatory/render.c Mandatory/events.c Mandatory/utils_func.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx_opengl_20191021
MLX_INCLUDE = -I$(MLX_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(MLX_DIR)/libmlx.a $(NAME)

$(NAME): $(OBJS) Mandatory/fractol.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INCLUDE) -c $< -o $@

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
