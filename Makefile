# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:37:24 by osarsari          #+#    #+#              #
#    Updated: 2023/08/21 18:11:05 by osarsari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

# The name of the executable
NAME	= so_long

# Compiler and compiling flags
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

# Debug, use with`make DEBUG=1`
ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -fsanitize=address
endif

# Folder names
SRCDIR	= src/
INCDIR	= includes/
OBJDIR	= obj/
LIB_DIR	= includes/lib/
MLX_DIR	= includes/mlx/

# Add include folders
CFLAGS	+= -I $(INCDIR) -I $(INCDIR)lib -I $(INCDIR)mlx

# Linking stage flags
LDFLAGS = -framework OpenGL -framework AppKit -L$(INCDIR)lib -lft -L$(INCDIR)mlx -lmlx

# List of source files (add your *.c files here)

SRCS =\
	so_long.c\
	$(SRCDIR)ft_validation.c\
	$(SRCDIR)ft_validation2.c\
	$(SRCDIR)ft_utils.c\
	$(SRCDIR)ft_array.c\
	$(SRCDIR)ft_init_image.c\
	$(SRCDIR)ft_load_map.c\
	$(SRCDIR)ft_key_press.c\
	$(SRCDIR)ft_move.c\

HEADERS =\
	$(INCDIR)so_long.h \
	$(INCDIR)lib/libft.h \
	$(INCDIR)mlx/mlx.h \

# String manipulation magic
SRC		:= $(notdir $(SRCS))
OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# Implicit rules
VPATH := $(SRCDIR) $(OBJDIR) $(shell find $(SRCDIR) -type d)

# ================================== RULES =================================== #

all : $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compiling
$(OBJDIR)%.o : %.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	@printf "$(GR)+$(RC)"
	@$(CC) $(CFLAGS) -c $< -o $@


# Linking
$(NAME): $(OBJS) $(LIB_DIR)libft.a $(MLX_DIR)libmlx.a
	@printf "\n$(GR)=== Compiled [$(CC) $(CFLAGS)] ===\n--- $(SRCS)$(RC)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "$(YE)&&& Linked [$(CC) $(LDFLAGS)] &&&\n--- $(NAME)$(RC)\n"

$(LIB_DIR)libft.a:
	@make -C $(LIB_DIR)

$(MLX_DIR)libmlx.a:
	@make -C $(MLX_DIR)

# Cleaning
clean :
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@printf "$(RE)--- Removing $(OBJDIR)$(RC)\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@make -C $(LIB_DIR) fclean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)

# Special rule to force to remake everything
re : fclean all

# This runs the program
run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME)

# This specifies the rules that does not correspond to any filename
.PHONY: all run clean fclean re $(LIBFT) $(MLX)