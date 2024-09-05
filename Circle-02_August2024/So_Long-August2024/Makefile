# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 17:11:28 by vbrabandt         #+#    #+#              #
#    Updated: 2024/09/05 16:46:58 by vbraband         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	so_long

cc						=	gcc
CFLAGS					=	-Wall -Wextra -Werror -g3 -MMD
rm						=	rm -rf

srcs					=	main.c error.c start_game.c end_game.c closing.c \
							tiles.c xpm_assets.c \
							check_map.c parse_map.c init_map.c init_tiles.c init_game.c fill_window.c \
							events.c movement.c move_count.c check_pos.c
               
src_dir					=	srcs
srcs_full				=	$(addprefix $(src_dir)/, $(srcs))

obj_dir					=	obj
obj						=	$(srcs:%.c=$(obj_dir)/%.o)

includes				=	-I ./includes/

libft_path				=	./lib/Libft_Modified-2024
libft					=	$(libft_path)/libft.a
libinclude				=	-L $(libft_path) -lft

mlx_path				=	./lib/MiniLibX
mlx						=	$(mlx_path)/libmlx_Linux.a
mlxflags				=	-L $(mlx_path) -lmlx -lXext -lX11

DEPS					=	$(OBJ:%.o=%.d)

$(obj_dir)/%.o:			srcs/%.c
						$(cc) $(CFLAGS) -I libft/srcs -I mlx -I srcs  -c $< -o $@ $(includes)

all:					$(NAME) 
						@echo "\033[32m[The Game is ready to be played]\033[0m"


$(NAME):				$(libft) $(obj_dir) $(obj)
						$(cc) $(CFLAGS) $(obj) -o $(NAME) $(libinclude) $(mlxflags)
						@echo "\033[32m[So_Long has been created]\033[0m"					
						

$(libft):
						$(MAKE) -C $(libft_path) all -s
						@echo "\033[32m[Libft has been created]\033[0m"

$(obj_dir):
						mkdir -p $(obj_dir)

-include $(DEPS)

clean:
						$(MAKE) -C $(libft_path) clean
						$(rm) $(obj_dir)
						@echo "\033[33m[Things have been cleaned up]\033[0m"

fclean:					clean
						$(MAKE) -C $(libft_path) fclean
						$(rm) $(NAME)
						@echo "\033[33m[Everything has been fully cleaned up]\033[0m"

re:						fclean 
						make all

run:					all
						./choose_map.sh

auto:					fclean 
						make all 
						make clean
						./choose_map.sh

debug:					fclean 
						make all 
						make clean
						valgrind --leak-check=full ./so_long ./maps/ex03.ber

.PHONY:	all clean fclean re libft
