# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 12:31:12 by vbrabandt         #+#    #+#              #
#    Updated: 2024/10/23 12:36:04 by vbrabandt        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap

cc						=	gcc
CFLAGS					=	-Wall -Werror -Wextra -g3 -MMD
rm						=	rm -rf
mkdir					=	mkdir -p

src_dir					=	srcs/
obj_dir					=	obj
includes				=	-I ./includes

libft_dir				=	./Libft_Modified-2024
libft					=	$(libft_dir)/libft.a
libinclude				=	-L $(libft_dir) -lft

commands_dir			=	$(src_dir)commands/push.c \
                        	$(src_dir)commands/rev_rotate.c \
                            $(src_dir)commands/rotate.c \
                            $(src_dir)commands/swap.c

main_dir				= 	$(src_dir)main/split.c

srcs					= 	$(commands_dir) $(PUSH_SWAP_DIR)

obj						= 	$(srcs:$(src_dir)%.c=$(obj_dir)/%.o)

DEPS					= 	$(obj:%.o=%.d)

-include $(DEPS)

silent					=	> /dev/null 2>&1


$(obj_dir)/%.o:			$(src_dir)%.c | $(obj_dir) $(obj_dir)/commands $(obj_dir)/push_swap
						@$(cc) $(CFLAGS) -I $(libft_dir) -I $(src_dir) -c $< -o $@ $(includes) $(silent)

all:					$(NAME)
						@echo "\033[4;36m[Program is ready]\033[0m"


$(NAME):				$(libft) $(obj)
						@$(CC) $(obj) $(CFLAGS) -o $(NAME) $(libinclude) $(silent)
						@echo "\033[4;36m[push_swap created]\033[0m"


$(LIBFT):
						@$(MAKE) -C $(LIBFT_DIR) all -s $(silent)
						@echo "\033[4;36m[Libft created]\033[0m"


$(obj_dir):
						@$(mkdir) $(obj_dir) $(silent)

$(obj_dir)/commands:
						@mkdir -p $(obj_dir)/commands $(silent)

$(obj_dir)/push_swap:
						@mkdir -p $(obj_dir)/push_swap $(silent)


clean:
						@$(MAKE) -C $(LIBFT_DIR) clean $(SILENT)
						@$(RM) $(OBJ_DIR) $(SILENT)
						@echo "\033[4;36m[Cleaned up]\033[0m"

fclean:					clean
						@$(MAKE) -C $(LIBFT_DIR) fclean $(SILENT)
						@$(RM) $(NAME) $(SILENT)
						@echo "\033[4;36m[Fully cleaned up]\033[0m"

re:						fclean
						@$(MAKE) all -s

.PHONY:					all clean fclean re libft
