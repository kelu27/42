/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 21:15:59 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:16:06 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_nbr_word(char const *s, char c);
static char		**ft_tab(char const *s, char c, int size, char **tab);

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;

	tab = NULL;
	size = ft_nbr_word(s, c);
	if ((tab = (char **)malloc((sizeof(char *) * size) + 1)) == NULL)
		return (NULL);
	tab = ft_tab(s, c, size, tab);
	return (tab);
}

static int		ft_nbr_word(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (j);
}

static char		**ft_tab(char const *s, char c, int size, char **tab)
{
	int		i;
	int		n;
	int		j;

	i = 0;
	n = 0;
	j = 0;
	while (s[i] != '\0' && n < size)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		if (s[i] != c)
		{
			while (s[i] != c)
				i++;
			tab[n] = ft_strsub(s, j, i - j);
			n++;
		}
	}
	tab[n] = '\0';
	return (tab);
}
