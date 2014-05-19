NAMES =	serveur

NAMEC = client

SRCDIRS = srcs/server/

SRCDIRC = srcs/client/

CFILES =	main.c client_files.c

SFILES =	main.c builtins.c serv_files.c

SRCS = $(addprefix $(SRCDIRS), $(SFILES))
SRCC = $(addprefix $(SRCDIRC), $(CFILES)) 
GCC = gcc -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)
HDDIR = includes/

all: client serveur

serveur:	$(OBJS)
			make -C libft/
			$(GCC) -o $(NAMES) $(OBJS) libft/libft.a
client:		$(OBJC)
			make -C libft/
			$(GCC) -o $(NAMEC) $(OBJC) libft/libft.a

%.o: %.c
	$(GCC) -c -o $@ $^  -I $(HDDIR)

clean:
		make -C libft/ clean
		rm -f $(OBJS)
		rm -f $(OBJC)

fclean: clean
		make -C libft/ fclean
		rm -rf $(NAMES)
		rm -rf $(NAMEC)

re: fclean all

.PHONY: clean fclean re