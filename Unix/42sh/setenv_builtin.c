/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:49:26 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 17:47:48 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		exec_setenv(char ***env, char **av, t_fd *fd)
{
	if (!av[1])
		print_env(*env, fd);
	else if (!av[2])
		return (ft_setenv(env, av[1], "", 1));
	else if (strstrlen(av) == 3)
		return (ft_setenv(env, av[1], av[2], 1));
	else
		ft_putendl_fd("usage: setenv [NAME] [value]", 2);
	return (1);
}

int		exec_unsetenv(char ***env, char **av)
{
	char	*name;
	int		i;
	int		size;

	i = 0;
	size = strstrlen(*env);
	if (strstrlen(av) != 2)
		ft_putendl_fd("usage: unsetenv [NAME]", 2);
	else
	{
		name = ft_strjoin(av[1], "=");
		while (i < size)
		{
			if (ft_strnequ(name, *(*env + i), ft_strlen(name)))
				break ;
			i++;
		}
		if (i == size)
		{
			ft_putendl_fd("unsetenv: [NAME] not found in env", 2);
			return (1);
		}
		return (ft_unsetenv(env, name, size));
	}
	return (1);
}
