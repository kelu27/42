/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:21:09 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/21 18:57:18 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static char		*ft_space(char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = i;
	while (s[i] != '\0')
		i++;
	return (ft_strsub(s, j, i - j));
}

static char		*ft_end_space(char *s)
{
	int		i;

	i = ft_strlen(s);
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	s[i] = '\0';
	return (s);
}

char			*ft_strtrim(char const *s)
{
	char	*new;

	new = ft_space(s);
	if (new == NULL)
		return (NULL);
	new = ft_end_space(new);
	if (new == NULL)
		return (NULL);
	return (new);
}
