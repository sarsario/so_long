MINILIBX_PATH = ./MiniLibX
MINILIBX = $(MINILIBX_PATH)/libmlx.a
LIBFT_PATH = ./Lib
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
# LDFLAGS = -L$(MINILIBX)
FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(MINILIBX) -I$(LIBFT_PATH) $(OBJS) $(LIBFT) $(MINILIBX) $(FRAMEWORK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MINILIBX) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MINILIBX):
	@make -C $(MINILIBX_PATH)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MINILIBX_PATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)
	# @make fclean -C $(MINILIBX_PATH)

re: fclean all

.PHONY: all clean fclean re