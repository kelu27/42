/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:20:49 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 18:08:39 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_strcmp_nocase(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			if ((s1[i] >= 65 && s1[i] <= 90) && (s1[i] + 32) == s2[i])
				i++;
			else if ((s1[i] >= 97 && s1[i] <= 122) && ((s1[i] - 32) == s2[i]))
				i++;
			else
				break ;
		}
		else
			i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int				ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}

int				ft_strequ_nocase(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp_nocase(s1, s2) == 0)
		return (1);
	return (0);
}
