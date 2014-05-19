/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:28:44 by jgil              #+#    #+#             */
/*   Updated: 2014/03/14 14:57:52 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = 0;
	if (!s || (r = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		ft_error(1, "ft_strsub");
	while (i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char		**tabsub(char **tab, unsigned int start, size_t len)
{
	char	**array;
	size_t	i;

	i = 0;
	if (!tab || (array = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		ft_error(1, "tabsub");
	while (i < len)
	{
		array[i] = ft_strdup(tab[start + i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}
