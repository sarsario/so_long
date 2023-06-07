MINILIBX_PATH = ./MiniLibX
MINILIBX = $(MINILIBX_PATH)/libmlx.a
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LDFLAGS = -L$(MINILIBX_PATH)

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MINILIBX) -c $< -o $@

$(MINILIBX):
	@make -C $(MINILIBX_PATH)

clean:
	$(RM) $(OBJS)
	@make clean -C $(MINILIBX_PATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(MINILIBX_PATH)

re: fclean all

.PHONY: all clean fclean re