/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:51:47 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 19:13:11 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if ((str = ((char *)malloc((sizeof(char) * size) + 1))) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
