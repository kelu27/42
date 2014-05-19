/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 18:19:32 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/10 13:26:49 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include "ft_select.h"

struct termios	ft_termios_init()
{
	struct termios new_term_config;

	tcgetattr(0, &new_term_config);
	*original_term() = new_term_config;
	new_term_config.c_lflag &= ~(ICANON);
	new_term_config.c_lflag &= ~(ECHO);
	new_term_config.c_cc[VMIN] = 1;
	new_term_config.c_cc[VTIME] = 0;
	tputs(tgetstr("ti", NULL), 1, tty_putchar);
	tputs(tgetstr("vi", NULL), 1, tty_putchar);
	tcsetattr(0, 0, &new_term_config);
	return (new_term_config);
}

void	ft_close_term(struct termios term)
{
	tputs(tgetstr("ve", NULL), 1, tty_putchar);
	tputs(tgetstr("te", NULL), 1, tty_putchar);
	tcsetattr(0, 0, &term);
	term.c_lflag = (ICANON);
	term.c_lflag = (ECHO);
}
