/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:28:57 by jgil              #+#    #+#             */
/*   Updated: 2014/02/04 11:40:33 by jgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

static int		ft_is_whitespace(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char			*ft_strtrim(char *s)
{
	int	len;

	if (!s)
		return (NULL);
	while (*s && ft_is_whitespace(*s))
		s++;
	len = ft_strlen(s) - 1;
	while (len > 0 && s[len] && ft_is_whitespace(s[len]))
		len--;
	return (ft_strsub(s, 0, len + 1));
}
