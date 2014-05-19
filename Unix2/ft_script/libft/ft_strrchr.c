/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:09:09 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:07:18 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	b;

	b = (char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	if (b == '\0')
		return ((char *)&s[i]);
	while (s[i] != s[0])
	{
		i--;
		if (s[i] == b)
			return ((char *)&s[i]);
	}
	return (NULL);
}
