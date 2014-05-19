/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:09:44 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:14:45 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	new = NULL;
	i = 0;
	if ((new = (char *)malloc(sizeof(len + 1))) != NULL)
	{
		while (i < len)
		{
			new[i] = s[start];
			i++;
			start++;
		}
	}
	new[i] = '\0';
	return (new);
}
