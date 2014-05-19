# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2014/04/21 19:18:02 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c ft_count_line.c draw.c draw_map.c print_lines.c init_coord.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -c $(SRC) -I /usr/X11/include/
	gcc -o $(NAME) $(OBJ) -L ./libft/ -lft -L /usr/X11/lib -lmlx -lXext -lX11

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
