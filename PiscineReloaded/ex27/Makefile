# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/31 20:58:29 by aleksei           #+#    #+#              #
#    Updated: 2021/11/01 10:26:47 by aleksei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
PATH_SRC = ./srcs/
HEADER = ./includes/
FLAG = -Wall -Wextra -Werror
OPTION = -I $(HEADER) -o $(NAME)
SRC = $(PATH_SRC)ft_display_file.c
OBJ = ft_display_file.o

all: $(NAME)

$(NAME):
		gcc $(FLAG) $(OPTION) $(SRC)
clean:
		rm -f $(OBJ)
fclean:
		rm -f $(NAME)

re: fclean all
