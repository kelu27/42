/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveniat <pveniat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:58:15 by pveniat           #+#    #+#             */
/*   Updated: 2014/02/13 18:54:40 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static size_t	ft_nbr_str(char const *s, char c)
{
	size_t	nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nbr++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (nbr);
}

static size_t	ft_to_end_word(char const *s, char c, unsigned int i)
{
	size_t	n;

	n = 0;
	while (s[i] != c && s[i] != '\0')
	{
		n++;
		i++;
	}
	return (n);
}

static size_t	ft_to_next(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s == c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	i3;
	size_t			len;
	char			**tab;

	if (!s)
		return (NULL);
	i3 = 0;
	tab = (char **)malloc(sizeof(*tab) * (ft_nbr_str(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (*s != '\0')
	{
		s += ft_to_next(s, c);
		if (ft_nbr_str(s, c) != 0)
		{
			len = ft_to_end_word(s, c, 0);
			tab[i3] = ft_strsub(s, 0, len);
			if (tab[i3] == NULL)
				return (NULL);
			i3++;
			s += len;
		}
	}
	tab[i3] = '\0';
	return (tab);
}
