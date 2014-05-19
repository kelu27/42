/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:34:56 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/11 15:29:20 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <termcap.h>
#include <termios.h>
#include <term.h>
#include <signal.h>
#include "ft_select.h"

struct	termios	*original_term()
{
	static struct termios	term;

	return (&term);
}

static void		ft_print(char *buf, struct termios new_term_config)
{
	int		ret;
	t_list	*l_a;

	l_a = *ft_create_double_circular();
	while (1)
	{
		if ((buf[0] == 27 || buf[0] == 10) && buf[1] == 0)
			break ;
		tputs(tgetstr("cl", NULL), 1, tty_putchar);
		ft_delete_content(ft_create3(), buf);
		if ((*ft_create3())->content == NULL)
			break ;
		ft_underline();
		ret = read(0, buf, 3);
		buf[ret] = '\0';
		ft_cursor(ft_create3(), buf);
		ft_cursor_select(ft_create3(), buf);
	}
	ft_close_term(new_term_config);
	ft_keep_entry(&l_a, buf);
	ft_putstr("\n");
}

int				main(int argc, char **argv)
{
	int				i;
	int				sign;
	char			buf[2048];
	struct termios	new_term_config;

	i = 1;
	if (tgetent(buf, getenv("TERM")) < 1)
		return (-1);
	new_term_config = ft_termios_init();
	while (sign <= 31)
		signal(sign++, ft_take_signal);
	if (argc == 1)
	{
		ft_putstr("missing arguments");
		return (0);
	}
	while (i < argc)
	{
		ft_push_back_doub_cir(ft_create_double_circular(), argv[i]);
		i++;
	}
	ft_print(buf, new_term_config);
	return (0);
}
