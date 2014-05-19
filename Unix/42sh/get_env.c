/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 11:16:57 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 18:06:47 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int		get_env(char **environ, char ***env)
{
	int		i;
	int		size;

	i = 0;
	if (!environ[0])
	{
		if (!(*env = (char **)malloc(sizeof(char *))))
			ft_error(1, "get_env");
		*env[0] = NULL;
		return (0);
	}
	size = strstrlen(environ);
	if (!(*env = (char **)malloc(sizeof(char *) * (size + 1))))
		ft_error(1, "get_env");
	while (i < size)
	{
		*(*env + i) = ft_strdup(*(environ + i));
		i++;
	}
	*(*env + i) = '\0';
	return (1);
}

int		strstrlen(char **tab)
{
	int		i;

	i = 0;
	if (tab[i])
	{
		while (tab[i])
			i++;
	}
	return (i);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		ft_error(1, "ft_strdup");
	len = 0;
	while (s1[len])
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}
