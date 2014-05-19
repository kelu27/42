#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vballu <vballu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 05:58:10 by vballu            #+#    #+#              #
#    Updated: 2014/03/08 21:48:20 by lcharpen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = alcu
LIBNAME = -lft
INCLUDES = ./libft/includes
SRCDIR = ./
LIBDIR = ./libft
SRC = 	\
		$(SRCDIR)display.c \
		$(SRCDIR)error.c \
		$(SRCDIR)main.c \
		$(SRCDIR)map.c \
		$(SRCDIR)ft_bpoint.c \
		$(SRCDIR)ft_check.c \
		$(SRCDIR)ft_putoken.c

OBJ = $(SRC:.c=.o)
EMACS = $(SRC:.c=.c~)
RM = /bin/rm

all: $(NAME)

$(NAME): $(OBJ)
	@(cd $(LIBDIR) && $(MAKE))
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBDIR) $(LIBNAME)

%.o: %.c
	$(CC) -o $@ -c $< -I$(INCLUDES) $(CFLAGS)

clean:
	$(RM) -f $(OBJ) $(EMACS) Makefile~
	@(cd $(LIBDIR) && $(MAKE) $@)

fclean: clean
	$(RM) -f $(NAME)
	@(cd $(LIBDIR) && $(MAKE) $@)


re: fclean all
