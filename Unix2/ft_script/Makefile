# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2014/05/02 17:06:06 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_script

SRC = main.c ft_cfmakeraw.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L ./libft/ -lft

%.o:	%.c
		gcc $(FLAGS) -c $^ -o $@

clean:	libclean
	rm -f $(OBJ)

libclean:
	make -C libft/ clean

libftclean:
	make -C libft/ fclean

fclean: clean libftclean
	rm -f $(NAME)

re: fclean all
