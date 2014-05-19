# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:18:13 by lcharpen          #+#    #+#              #
#    Updated: 2014/01/28 18:52:48 by lcharpen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_strcmp.c \
	  ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c \
	  ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncmp.c ft_strncat.c ft_strchr.c \
	  ft_strdup.c ft_strlcat.c ft_strstr.c ft_strrchr.c ft_strnstr.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strclr.c ft_memdel.c ft_memalloc.c \
	  ft_strnew.c ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c \
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	  ft_strtrim.c ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c \
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c get_next_line.c \

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I ./includes
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o:	%.c
	gcc $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
