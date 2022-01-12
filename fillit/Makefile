#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 14:07:30 by jlehtine          #+#    #+#              #
#    Updated: 2021/12/21 19:04:40 by jlehtine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = 	main.c tetriminos.c read_tetriminos.c add_tetrimino.c\
	   	tetrimino_lines.c free_memory.c map_operations.c solve.c char_map.c
CC = gcc
FLAGS = -Wall -Wextra -Werror -o $(NAME) -I $(INCLUDES) 
LIBFT = -L libft -lft
INCLUDES = libft/includes

$(NAME):
	@echo "Compiling..."
	@make -C libft --no-print-directory
	@$(CC) $(SRCS) $(FLAGS) $(LIBFT)

all: $(NAME)
	
clean:
	@echo "Cleaning object files..."
	@make -C libft clean --no-print-directory

fclean: clean
	@echo "Cleaning binary..."
	@make -C libft fclean --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
