# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2014/03/23 19:39:42 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRLIB = libft/

NAME = lem-in

SRC = ft_check.c \
	  ft_check_tools.c \
	  ft_map.c \
	  ft_pipe.c \
	  ft_find_path.c \
	  ft_path_tools.c \
	  ft_room.c \
	  ft_lstadd_tail.c \
	  ft_print_ant_hill.c \
	  main.c

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@(cd $(DIRLIB) && $(MAKE))
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(DIRLIB)libft.a
	
%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJECTS)
	@(cd $(DIRLIB) && $(MAKE) $@)

fclean: clean
	@rm -f $(NAME)
	@(cd $(DIRLIB) && $(MAKE) $@)

re: fclean all

.PHONY: all clean fclean re
