# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2013/12/13 20:57:57 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_list_dir.c ft_list_dir_a.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib
		gcc $(FLAGS) -c $(SRC)
		gcc -o $(NAME) $(OBJECTS) -L libft/ -lft

lib:
		make -C libft/

clean: libclean
		rm -f $(OBJECTS)

libclean:
		make -C libft/ clean

libfclean:
		make -C libft/ fclean

fclean: clean libfclean
		rm -f $(NAME)

re: fclean all
