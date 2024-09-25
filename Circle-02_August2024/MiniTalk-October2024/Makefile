# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:38:48 by vbraband          #+#    #+#              #
#    Updated: 2024/09/25 16:20:38 by vbrabandt        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MiniTalk Makefile #

cc			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
rm			=	rm -rf

client_name	=	client
client_srcs	=	../srcs/client.c

server_name	=	server
server_srcs	=	../srcs/server.c

obj_dir		=	obj
obj			=	$(srcs:%.c=$(src_dir)/%.o)

includes	=	-I ./includes/

libft_path	=	../lib/Libft_Modified-2024
libft		=	$(libft_path)/libft.a
libinclude	=	-L $(libft_path) -lft

all: $(client_name) $(server_name)

$(client_name): $(client_srcs) $(libft)
		$(cc) $(CFLAGS) -o $@ $(client_srcs) $(libinclude)
		@echo "\033[32m[Client executable has been compiled]\033[0m"

$(server_name): $(server_srcs) $(libft)
		$(cc) $(CFLAGS) -o $@ $(server_srcs) $(libinclude)
		@echo "\033[32m[Server executable has been compiled]\033[0m"

$(libft):
		$(MAKE) -C $(libft_path) all -s
		@echo "\033[32m[Libft has been created]\033[0m"

$(obj_dir):
		mkdir -p $(obj_dir)

clean:
		$(MAKE) -C $(libft_path) clean
		$(rm) $(obj_dir)
		@echo "\033[33m[Object files have been deleted]\033[0m"

fclean: clean
		$(MAKE) -C $(libft_path) fclean
		$(rm) $(client_name) $(server_name)
		@echo "\033[33m[Object files and executables has been deleted]\033[0m"

re:		fclean
		make all

auto:	fclean
		make all
		make clean
		./server
		./client

debug:	fclean
		make all
		make clean
		valgrind --leak-check=full ./server
		valgrind --leak-check=full ./client