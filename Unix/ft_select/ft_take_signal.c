/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:07:16 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/11 15:22:16 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include <term.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"

static void	ft_sigtstp(void);
static void ft_sigint(void);

void		ft_take_signal(int sign)
{
	if (sign == SIGTSTP || sign == SIGTTIN || sign == SIGTTOU)
		ft_sigtstp();
	if (sign == SIGCONT || sign == SIGURG || sign == SIGCHLD || sign == SIGIO ||
		sign == SIGINFO)
	{
		ft_termios_init();
		ft_underline();
		signal(SIGTSTP, ft_take_signal);
	}
	if (sign == SIGINT || sign == SIGTERM || sign == SIGHUP || sign == SIGPIPE
		|| sign == SIGALRM || sign == SIGXCPU || sign == SIGXFSZ || sign ==
		SIGVTALRM || sign == SIGPROF || sign == SIGUSR1 || sign == SIGUSR2 ||
		sign == SIGQUIT || sign == SIGILL || sign == SIGTRAP || sign == SIGABRT
		|| sign == SIGEMT || sign == SIGFPE || sign == SIGBUS || sign == SIGSEGV
		|| sign == SIGSYS)
		ft_sigint();
	if (sign == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 1, tty_putchar);
		ft_underline();
	}
}

static void	ft_sigtstp(void)
{
	char	cp[2] =
	{
		original_term()->c_cc[VSUSP], 0
	};

	if (isatty(1))
	{
		tputs(tgetstr("ve", NULL), 1, tty_putchar);
		tputs(tgetstr("te", NULL), 1, tty_putchar);
		tcsetattr(0, 0, original_term());
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
	}
}

static void	ft_sigint(void)
{
	tputs(tgetstr("te", NULL), 1, tty_putchar);
	tputs(tgetstr("ve", NULL), 1, tty_putchar);
	tcsetattr(0, 0, original_term());
	signal(SIGTSTP, SIG_DFL);
	exit (0);
}
