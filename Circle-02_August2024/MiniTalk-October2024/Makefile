# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 13:38:48 by vbraband          #+#    #+#              #
#    Updated: 2024/09/25 15:59:43 by vbrabandt        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MiniTalk Makefile #

cc		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

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

