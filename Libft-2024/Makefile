# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 09:38:04 by vbraband          #+#    #+#              #
#    Updated: 2024/06/14 12:16:36 by vbraband         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRCs = libft.h *.c

ALL:
	$(CC) $(SRCs) -o $(NAME) -Wall -Wextra -Werror
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean re