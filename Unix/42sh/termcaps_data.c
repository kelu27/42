/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:40:03 by jflorimo          #+#    #+#             */
/*   Updated: 2014/03/27 18:45:32 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <unistd.h>
#include "shell.h"

t_data			init_data(void)
{
	t_data	data;

	data.read_char[0] = 0;
	data.read_char[1] = 0;
	data.read_char[2] = 0;
	data.read_char[3] = 0;
	data.read_char[4] = 0;
	return (data);
}

int				tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

TERMIOS			*ft_init_term(void)
{
	static TERMIOS	term;

	return (&term);
}

void			init_shell(struct termios *m_term)
{
	tcgetattr(0, m_term);
	*ft_init_term() = (*m_term);
	m_term->c_lflag &= ~(ICANON);
	m_term->c_lflag &= ~(ECHO);
//	m_term->c_cc[VMIN] = 1;
//	m_term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, m_term);
}

void			term_close(struct termios *term)
{
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 1, term);
}
