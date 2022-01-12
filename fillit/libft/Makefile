# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlehtine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 18:32:41 by jlehtine          #+#    #+#              #
#    Updated: 2021/12/22 15:43:44 by jlehtine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = 	ft_sqrt.c\
	ft_atoi.c\
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdup.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putnbr_fd.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_strjoin.c\
	ft_itoa.c\
	ft_strsub.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strclr.c\
	ft_strdel.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_memprint.c\
	ft_min.c\
	ft_max.c\
	ft_isspace.c\
	ft_itoa_base.c\
	ft_bintoi.c\
	ft_pow.c\
	ft_strrev.c\
	ft_putaddr.c\
	ft_abs.c\
	get_next_line.c\
	ft_memrealloc.c\
	ft_bitrev.c\
	ft_bitmod.c\
	ft_bitprint.c\
	ft_bitswap.c

OBJS = $(patsubst %.c, %.o, $(SRCS))
CC = gcc
FLAGS = -Wall -Wextra -Werror -c -I $(INCLUDES)
INCLUDES = includes/

$(NAME): 
	@echo "Compiling..."
	@$(CC) $(FLAGS) $(SRCS)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)
	
clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning binary..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
