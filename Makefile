NAME = fractol

SRCS = main.c fractals.c render.c events.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)  # Ensure MLX is compiled before linking
	$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean  # Clean MLX objects too

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
