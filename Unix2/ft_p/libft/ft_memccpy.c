/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 13:46:07 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:01:26 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t					i;
	unsigned char			d;
	unsigned char			*s1b;
	const unsigned char		*s2b;

	i = 0;
	d = (unsigned char)c;
	s1b = s1;
	s2b = s2;
	while (*s2b && (i < n))
	{
		if (s2b[i] == d)
		{
			s1b[i] = s2b[i];
			return (&((unsigned char*)s1b)[i + 1]);
		}
		s1b[i] = s2b[i];
		i++;
	}
	return (NULL);
}
