# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 12:31:12 by vbrabandt         #+#    #+#              #
#    Updated: 2024/10/24 16:45:10 by vbrabandt        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = gcc
CFLAGS      = -Wall -Werror -Wextra -g3 -MMD
RM          = rm -rf
MKDIR       = mkdir -p

SRC_DIR     = srcs
OBJ_DIR     = obj
INCLUDES    = -I ./includes

LIBFT_DIR   = ./Libft_Modified-2024
LIBFT       = $(LIBFT_DIR)/libft.a
LIBINCLUDE  = -L $(LIBFT_DIR) -lft

COMMANDS_DIR = $(SRC_DIR)/commands/push.c \
               $(SRC_DIR)/commands/rev_rotate.c \
               $(SRC_DIR)/commands/rotate.c \
               $(SRC_DIR)/commands/sort_stacks.c \
               $(SRC_DIR)/commands/sort_three.c \
               $(SRC_DIR)/commands/swap.c

STACK_DIR   = $(SRC_DIR)/stack/split.c \
              $(SRC_DIR)/stack/stack_init.c \
              $(SRC_DIR)/stack/stack_utils.c

MAIN_DIR    = $(SRC_DIR)/main/split.c

SRCS        = $(COMMANDS_DIR) $(STACK_DIR) $(MAIN_DIR)
OBJS        = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)
DEPS        = $(OBJS:%.o=%.d)

-include $(DEPS)

SILENT      = > /dev/null 2>&1

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(OBJ_DIR)/commands $(OBJ_DIR)/push_swap
    @$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(SRC_DIR) -c $< -o $@ $(INCLUDES) $(SILENT)

all: $(NAME)
    @echo "\033[4;36m[Program is ready]\033[0m"

$(NAME): $(LIBFT) $(OBJS)
    @$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LIBINCLUDE) $(SILENT)
    @echo "\033[4;36m[push_swap created]\033[0m"

$(LIBFT):
    @$(MAKE) -C $(LIBFT_DIR) all -s $(SILENT)
    @echo "\033[4;36m[Libft created]\033[0m"

$(OBJ_DIR):
    @$(MKDIR) $(OBJ_DIR) $(SILENT)

$(OBJ_DIR)/commands:
    @mkdir -p $(OBJ_DIR)/commands $(SILENT)

$(OBJ_DIR)/push_swap:
    @mkdir -p $(OBJ_DIR)/push_swap $(SILENT)

clean:
    @$(MAKE) -C $(LIBFT_DIR) clean $(SILENT)
    @$(RM) $(OBJ_DIR) $(SILENT)
    @echo "\033[4;36m[Cleaned up]\033[0m"

fclean: clean
    @$(MAKE) -C $(LIBFT_DIR) fclean $(SILENT)
    @$(RM) $(NAME) $(SILENT)
    @echo "\033[4;36m[Fully cleaned up]\033[0m"

re: fclean
    @$(MAKE) all -s

.PHONY: all clean fclean re libft
