# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2014/04/20 12:52:24 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LN_NAME = libft_malloc.so

SRC = malloc.c free.c ft_putstr.c new_header.c realloc.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -shared

all: $(NAME)

$(NAME): $(OBJECTS)
		gcc -o $(NAME) $(OBJECTS) $(FLAGS)
		/bin/rm -rf $(LN_NAME)
		ln -s $(NAME) $(LN_NAME)

%.o: %.c
		gcc $(FLAGS) -c $^ -o $@

clean:
		/bin/rm -f $(OBJECTS)

fclean: clean
		/bin/rm -f $(NAME)
		/bin/rm -f $(LN_NAME)

re: fclean all

.PHONY: all clean fclean re
