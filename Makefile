MLX_PATH = ./includes/mlx
MLX_LIB = $(MLX_PATH)/libmlx.a
LIBFT_PATH = ./includes/lib
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT = -L $(LIBFT_PATH) -lft
MLX = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
LIBS = $(LIBFT) $(MLX)
SRCS = src/ft_utils.c src/ft_validation.c src/ft_array.c\
	so_long.c
OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
INCS = -I ./includes -I $(MLX_PATH) -I $(LIBFT_PATH)
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re