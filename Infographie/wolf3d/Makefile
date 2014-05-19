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

NAME = wolf3d

NAME_MINILIBX = mlx

LDFLAGS +=	-L/usr/X11/lib -lXext -lX11 -lmlx

SRC = main.c tools.c map.c ft_count_line.c timer.c key_hook.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -c $(SRC) -I/usr/X11/include
	gcc -o $(NAME) $(LDFLAGS) $(OBJ) -L ./libft/ -lft 

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
