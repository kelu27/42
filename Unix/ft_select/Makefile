# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2014/01/10 15:59:11 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = main.c ft_push_back_doub_cir.c ft_strcpy.c \
	  ft_create_double_circular.c ft_putstr.c ft_strlen.c ft_strdup.c \
	  tty_putchar.c ft_underline.c ft_take_signal.c ft_item_init.c\
	  ft_delete_content.c ft_cursor_select.c ft_cursor.c ft_keep_entry.c\
	  ft_term_config.c ft_putstr_fd.c ft_tools.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJECTS) -L /usr/lib -ltermcap

%.o:	%.c
		gcc $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
