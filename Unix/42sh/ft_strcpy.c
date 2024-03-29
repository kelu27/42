/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:20:02 by jgil              #+#    #+#             */
/*   Updated: 2014/01/25 20:47:04 by jgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*ft_strcpy(char *s1, const char *s2)
{
	char	*s;

	s = s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s);
}
