/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 12:02:44 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/21 18:56:47 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			ft_countwords(char const *s, char c)
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

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	if ((str = (char **)malloc(sizeof(char*) * (ft_countwords(s, c) + 1)))
			== NULL)
		return (NULL);
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
