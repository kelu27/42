/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:11:49 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 18:07:04 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

static int		ft_countwords(char const *s, char c)
{
	int		i;
	int		w;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			w++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (w);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	if ((str = (char **)malloc(sizeof(char*) * (ft_countwords(s, c) + 1)))\
			== NULL)
		ft_error(1, "ft_strsplit");
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
		{
			str[l] = ft_strsub(s, j, i - j);
			l++;
		}
	}
	str[l] = '\0';
	return (str);
}
