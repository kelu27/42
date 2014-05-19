#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/25 21:06:24 by jgil              #+#    #+#              #
#    Updated: 2014/03/27 20:28:04 by lcharpen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh

SRC = builtins.c \
	cd_builtin.c \
	change_into.c \
	do_the_cmd.c \
	ft_putstr.c \
	ft_strcpy.c \
	ft_strjoin.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strsplit.c \
	ft_strsub.c \
	ft_strcmp.c \
	get_env.c \
	main.c \
	setenv.c \
	setenv_builtin.c \
	pipe.c \
	ft_strtrim.c \
	ft_save_path.c \
	ft_echo.c \
	ft_strequ.c \
	prompt.c \
	reader.c \
	lst_elements.c \
	termcaps_data.c \
	key_implementation.c \
	save_line_checker.c \
	ft_isprint.c \
	parser.c \
	token.c \
	tokenlist.c \
	tree.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_operator.c \
	ft_init_fd.c \
	ft_error.c \
	ft_operator_two.c \
	reader_two.c \
	board_reader.c \
	cmd_list.c \
	ft_strjoin_char.c \
	ft_strncpy.c \
	echo_option.c \
	ft_operator_four.c \
	ft_atoi.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		@gcc $(FLAGS) -o $(NAME) $(SRC) -L /usr/lib -ltermcap

%.o:	%.c
		gcc $(FLAGS) -c $^ -o $@

clean:
		@rm -f $(OBJECTS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
