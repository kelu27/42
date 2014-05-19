/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:45:53 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 18:11:54 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include "shell.h"

static int		exec_cmd(char *cmd, char **av, char **env, t_fd *fd)
{
	pid_t	father;

	if (av[0])
	{
		father = fork();
		if (!father)
		{
			if (fd->fdout != 1)
				dup2(fd->fdout, 1);
			if (fd->fdin != 0)
				dup2(fd->fdin, 0);
			execve(cmd, av, env);
		}
		else
		{
			waitpid(father, 0, 0);
			if (fd->fdout != 1)
				close(fd->fdout);
			if (fd->fdin != 0)
				close(fd->fdin);
		}
	}
	return (1);
}

static int		try_exec_cmd(char **path, char **av, char **env, t_fd *fd)
{
	int				i;
	int				done;
	struct stat		s;

	done = 0;
	i = 0;
	while (path[i] && !done)
	{
		if (!stat(path[i], &s) && !access(path[i], X_OK))
		{
			done = 1;
			exec_cmd(path[i], av, env, fd);
		}
		i++;
	}
	return (done);
}

static int		find_the_path(char **env, char ***paths)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ("PATH", *(env + i), 4))
			break ;
		i++;
	}
	if (!env[i])
	{
		if (!save_path(env, 1))
			return (0);
		*paths = ft_strsplit(ft_strsub(save_path(env, 1), 5,
					ft_strlen(save_path(env, 1))), ':');
		return (1);
	}
	*paths = ft_strsplit(ft_strsub(env[i], 5, ft_strlen(env[i])), ':');
	return (1);
}

static int		prepare_exec(char ***env, char **argts, t_fd *fd)
{
	char	**paths;
	int		i;
	int		size;

	i = 0;
	if (!find_the_path(*env, &paths))
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(argts[0], 2);
		return (0);
	}
	size = strstrlen(paths);
	while (i < size)
	{
		*(paths + i) = ft_strjoin(ft_strjoin(paths[i], "/"), argts[0]);
		i++;
	}
	if (!try_exec_cmd(paths, argts, *env, fd))
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(argts[0], 2);
		return (0);
	}
	return (1);
}

int				do_the_cmd(char ***env, char **argts, t_fd *fd)
{
	struct stat		s;

	if (is_it_builtins(env, argts, fd))
		return (1);
	if (argts[0] && find_char(argts[0], '/') >= 0)
	{
		if (!stat(argts[0], &s) && !access(argts[0], X_OK))
			return (exec_cmd(argts[0], argts, *env, fd));
		else
		{
			ft_putstr_fd("42sh: no such file or directory: ", 2);
			ft_putendl_fd(argts[0], 2);
			return (0);
		}
		return (1);
	}
	else
		return (prepare_exec(env, argts, fd));
}
