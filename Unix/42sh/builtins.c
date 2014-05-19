/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 19:31:46 by jgil              #+#    #+#             */
/*   Updated: 2014/03/27 21:12:43 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int				is_it_builtins(char ***env, char **av, t_fd *fd)
{
	int		i;

	if (ft_strequ(av[0], "exit"))
	{
		term_close(ft_init_term());
		ft_putendl("\033[31mexit\033[0m");
		i = ft_atoi(av[1]);
		exit(i);
	}
	else if (ft_strequ(av[0], "cd"))
		return (ft_cd(env, av));
	else if (ft_strequ(av[0], "setenv"))
		return (exec_setenv(env, av, fd));
	else if (ft_strequ(av[0], "unsetenv"))
		return (exec_unsetenv(env, av));
	else if (ft_strequ_nocase(av[0], "env"))
		return (ft_env(*env, av, fd));
	else if (ft_strequ_nocase(av[0], "echo"))
		return (ft_echo(av, fd));
	return (0);
}

int				print_env(char **env, t_fd *fd)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], fd->fdout);
		i++;
	}
	return (1);
}

static void		send_to_setenv(char ***env, char *str)
{
	int		i;
	char	*name;
	char	*value;

	i = find_char(str, '=');
	name = ft_strsub(str, 0, i);
	i++;
	value = ft_strsub(str, i, ft_strlen(str) - i);
	ft_setenv(env, name, value, 1);
}

int				ft_env(char **env, char **arg, t_fd *fd)
{
	int		i;
	char	**tmp;

	i = 1;
	if (!arg[1])
		return (print_env(env, fd));
	else if (ft_strequ(arg[1], "-i"))
	{
		i = 2;
		if (!(tmp = (char **)malloc(sizeof(char *))))
			ft_error(1, "ft_env");
		tmp[0] = NULL;
	}
	else
		tmp = env;
	while (arg[i])
	{
		if (find_char(arg[i], '=') >= 0)
			send_to_setenv(&tmp, arg[i]);
		else
			return (do_the_cmd(&tmp, tabsub(arg, i, strstrlen(arg) - i), fd));
		i++;
	}
	return (print_env(tmp, fd));
}
