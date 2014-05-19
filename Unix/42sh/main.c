/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 11:14:24 by jgil              #+#    #+#             */
/*   Updated: 2014/03/27 11:33:37 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <termcap.h>
#include "shell.h"

static void		sig_handler(int sign)
{
	(void)sign;
}

static void		signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGINFO, sig_handler);
}

static int		my_main_bis(char ***env, t_data data)
{
	t_token	*token;
	char	*line;

	token = NULL;
	if (reader(&line, data) > 0)
	{
		term_close(ft_init_term());
		write(1, "\n", 1);
		line = change_into('	', ' ', line);
		token = ft_lexertoken(ft_strtrim(line));
		infix(env, ft_parser(token), 0);
		return (1);
	}
	else
	{
		ft_putendl("");
		return (1);
	}
	return (0);
}

int				main(void)
{
	extern char		**environ;
	char			**env;
	int				ret;
	t_data			data;

	data = init_data();
	env = NULL;
	ret = 1;
	if (tgetent(data.buffer, getenv("TERM")) < 1)
		return (-1);
	init_shell(&(data.m_term));
	signals();
	if (get_env(environ, &env))
		save_path(env, 0);
	ft_setenv(&env, "SHELL", "42sh", 1);
	while (ret)
	{
		ft_putstr(ft_prompt());
		ret = my_main_bis(&env, data);
		init_shell(&(data.m_term));
	}
	ft_putendl("\033[31mexit\033[0m");
	term_close(ft_init_term());
	return (0);
}
