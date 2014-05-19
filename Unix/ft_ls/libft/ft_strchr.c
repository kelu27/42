/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:21:16 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:05:56 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	b = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == b)
			return ((char *)&s[i]);
		i++;
	}
	if (b == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
