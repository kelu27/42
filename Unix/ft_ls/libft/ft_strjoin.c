/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:01:01 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:15:01 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	new = NULL;
	i = 0;
	j = 0;
	if ((new = (char *)malloc(sizeof(*s1 + *s2))) != NULL)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		j = i;
		i = 0;
		while (s2[i] != '\0')
		{
			new[j] = s2[i];
			i++;
			j++;
		}
	}
	new[j] = '\0';
	return (new);
}
