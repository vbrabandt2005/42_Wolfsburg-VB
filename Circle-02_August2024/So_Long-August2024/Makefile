# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 14:33:57 by vbraband          #+#    #+#              #
#    Updated: 2024/08/15 12:05:44 by vbraband         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
NAME_BONUS	= so_long_bonus

cc 			= cc
srcs 		= 
objects		= $(srcs:.c=.o)
CFLAGS		= -Wall -Wextra -Werror
rm			= rm -rf

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
 
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif


all: $(NAME)

$(NAME): $(objects)
	ar -rcs $(NAME) $(objects)

clean:
	$(rm) $(objects)

fclean: clean
	$(rm) $(NAME)

re: fclean $(NAME)

auto: all clean

fuck: fclean
	$(rm) a.out

.PHONY: all clean fclean re