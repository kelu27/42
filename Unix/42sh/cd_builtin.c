/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:42:17 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 22:52:00 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "shell.h"

static int		go_to_dest(char ***env, char **av)
{
	char			pwd[1024];
	char			dest[1024];
	struct stat		s;

	pwd[0] = '\0';
	dest[0] = '\0';
	if (!stat(av[1], &s) && !av[2])
	{
		getcwd(pwd, 1024);
		chdir(av[1]);
		getcwd(dest, 1024);
		ft_setenv(env, "OLDPWD", pwd, 1);
		ft_setenv(env, "PWD", dest, 1);
		return (1);
	}
	else if (!av[2])
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (av[2])
		ft_putstr_fd("cd: string not in pwd: ", 2);
	ft_putendl_fd(av[1], 2);
	return (1);
}

static int		go_to_name(char ***env, char *name)
{
	char			*dest;
	char			pwd[1024];
	struct stat		s;

	pwd[0] = '\0';
	getcwd(pwd, 1024);
	if (!(dest = get_in_env(*env, name)))
	{
		ft_putstr_fd("cd: variable ", 2);
		write(2, name, ft_strlen(name) - 1);
		ft_putendl_fd(" is missing in env", 2);
		return (1);
	}
	if (stat(dest, &s))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(dest, 2);
		write(2, name, ft_strlen(name) - 1);
		ft_putendl_fd(" corrupted", 2);
		return (1);
	}
	ft_setenv(env, "OLDPWD", pwd, 1);
	ft_setenv(env, "PWD", dest, 1);
	return (chdir(dest) + 1);
}

char			*get_in_env(char **env, char *target)
{
	char	*save;
	int		i;
	int		len;

	i = 0;
	save = NULL;
	len = ft_strlen(target);
	while (env[i])
	{
		if (ft_strnequ(env[i], target, len))
			save = ft_strsub(env[i], len, ft_strlen(env[i]) - len);
		i++;
	}
	if (save == NULL)
		return (NULL);
	return (save);
}

int				ft_cd(char ***env, char **av)
{
	int		i;

	if (strstrlen(av) < 4)
	{
		if (!av[1])
			return (go_to_name(env, "HOME="));
		if (ft_strnequ(av[1], "-", ft_strlen(av[1])))
		{
			i = go_to_name(env, "OLDPWD=");
			return (i);
		}
		else
			return (go_to_dest(env, av));
	}
	ft_putendl_fd("cd: too many arguments", 2);
	return (0);
}
