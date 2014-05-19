# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2013/12/29 20:26:52 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c ft_atoi.c ft_isdigit.c ft_create_elem.c ft_list_push_back.c \
ft_swap_s.c ft_take_p.c ft_list_push_front.c ft_rotate_r.c ft_rotate_rr.c \
ft_check_content.c ft_putstr.c ft_last_content.c ft_algo_sort.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJECTS)

%.o:	%.c
		gcc $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
