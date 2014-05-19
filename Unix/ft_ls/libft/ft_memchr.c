/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:42:29 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:02:56 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	while (n != i)
	{
		if (s1[i] == (unsigned char)c)
			return ((unsigned char *)&s1[i]);
		i++;
	}
	return (NULL);
}
