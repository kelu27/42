# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2013/12/22 19:35:52 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_check_arg.c ft_putnbr.c ft_nsize.c ft_putchar.c \
	ft_strlen.c ft_putstr.c ft_putnbr_ld.c ft_nsize_ld.c ft_check_num.c \
	ft_isdigit.c ft_atoi.c ft_putnbr_ui.c ft_nsize_ui.c ft_putnbr_ul.c \
	ft_nsize_ul.c ft_dec_to_oct.c ft_strnew.c ft_nsize_oct.c ft_nsize_oct_ul.c \
	ft_dec_to_oct_ul.c ft_isdigit.c ft_check_num.c ft_dec_to_hex.c \
	ft_nsize_hex.c ft_dec_to_hex_ul.c ft_nsize_hex_ul.c ft_check_arg_o.c \
	ft_check_diez.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)

%.o:	%.c
	gcc $(FLAGS) -c $^ -o $@
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

