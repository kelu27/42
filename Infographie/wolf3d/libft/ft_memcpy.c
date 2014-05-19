/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:53:09 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 16:34:14 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	const char		*s2b;

	i = 0;
	s1b = s1;
	s2b = s2;
	while (i != n)
	{
		s1b[i] = s2b[i];
		i++;
	}
	s1b = s1;
	return (s1);
}
