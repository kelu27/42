/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:01:44 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/11 15:26:33 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include "ft_select.h"

int		ft_main_init(int argc, char **argv)
{
	t_list			*l_a;
	int				i;
	char			buf[2048];
	struct termios	new_term_config;

	if (tgetent(buf, getenv("TERM")) < 1)
		return (-1);
	new_term_config = ft_termios_init();
	signal(SIGTSTP, ft_take_signal);
	signal(SIGCONT, ft_take_signal);
	signal(SIGINT, ft_take_signal);
	signal(SIGWINCH, ft_take_signal);
	i = 1;
	if (argc == 1)
	{
		ft_putstr("missing arguments");
		return (0);
	}
	l_a = *ft_create_double_circular();
	while (i < argc)
	{
		ft_push_back_doub_cir(ft_create_double_circular(), argv[i]);
		i++;
	}
	return (0);
}
