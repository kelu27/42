/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:13:49 by elivet            #+#    #+#             */
/*   Updated: 2014/03/25 12:06:45 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

char	*ft_strjoin_char(char *s1, char c)
{
	char	*r;
	int		i;

	if (!s1)
		return (NULL);
	r = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!r)
		return (NULL);
	i = 0;
	while (*s1)
		r[i++] = *(s1++);
	r[i++] = c;
	r[i] = '\0';
	return (r);
}
