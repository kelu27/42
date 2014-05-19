/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 15:35:03 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 17:48:27 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

static char		*get_new_value(char *name, char *value)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(name) + ft_strlen(value) + 1)))
		return (NULL);
	str = ft_strdup(name);
	str = join_free(str, value);
	return (str);
}

static void		add_in_env(char ***env, char *name, char *value, int size)
{
	char	**new_env;
	int		i;

	i = 0;
	if (!(new_env = (char **)malloc(sizeof(char *) * (size + 2))))
		ft_error(1, "add_in_env");
	while (i < size)
	{
		new_env[i] = ft_strdup(*(*env + i));
		i++;
	}
	new_env[i] = get_new_value(name, value);
	new_env[i + 1] = '\0';
	free(*env);
	*env = new_env;
}

int				ft_setenv(char ***env, char *name, char *value, int overwrite)
{
	int		i;
	int		size;
	int		n;

	i = 0;
	size = strstrlen(*env);
	name = ft_strjoin(name, "=");
	n = ft_strlen(name);
	while (i < size)
	{
		if (ft_strnequ(name, (*env)[i], n) && overwrite != 0)
		{
			free((*env)[i]);
			(*env)[i] = get_new_value(name, value);
			if ((*env)[i] == NULL)
				return (0);
			return (1);
		}
		else if (ft_strnequ(name, (*env)[i], n) && overwrite == 0)
			return (0);
		i++;
	}
	if (i == size)
		add_in_env(env, name, value, size);
	return (1);
}

int				ft_unsetenv(char ***env, char *name, int size)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_env = (char **)malloc(sizeof(char *) * (size))))
		ft_error(1, "ft_unsetenv");
	while (j < size)
	{
		j = (ft_strnequ(name, *(*env + j), ft_strlen(name)) ? j + 1 : j);
		if (j >= size)
			break ;
		if ((new_env[i] = ft_strdup(*(*env + j))) == NULL)
			return (0);
		i++;
		j++;
	}
	new_env[i] = '\0';
	free(*env);
	*env = new_env;
	return (1);
}
