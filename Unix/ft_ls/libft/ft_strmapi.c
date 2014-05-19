/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:10:10 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 12:40:54 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	char	*new;
	unsigned int	i;

	new = NULL;
	i = 0;
	if ((new = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = f(i, (s[i]));
		i++;
	}
	new[i] = '\0';
	return (new);
}
