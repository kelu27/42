/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_into.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:35:25 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 22:38:30 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

char	*change_into(char a, char b, char *line)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (line)
	{
		len = ft_strlen(line);
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			ft_error(1, "change_into");
		while (i < len)
		{
			if (line[i] == a)
				str[i] = b;
			else
				str[i] = line[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (line);
}
