/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:12:01 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:03:13 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	s1b;
	unsigned char	s2b;

	while (n > 0)
	{
		s1b = *(unsigned char *)s1;
		s2b = *(unsigned char *)s2;
		if (s1b != s2b)
			return (s1b - s2b);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
