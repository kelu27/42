/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballu <vballu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:47:23 by vballu            #+#    #+#             */
/*   Updated: 2014/03/08 21:48:09 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alcu.h"

void		ft_create_map(char *line, char *col)
{
	int		tall;
	int		wide;
	int		i;

	i = 0;
	tall = ft_atoi(line);
	wide = ft_atoi(col);
	if (tall > 5 && wide > 6)
	{
		map_singleton()->tall = tall;
		map_singleton()->wide = wide;
		map_singleton()->stage = (char**)malloc(sizeof(char *) * tall);
		while (i < tall)
		{
			map_singleton()->stage[i] = (char *)malloc(sizeof(char) * wide);
			ft_bpoint(map_singleton()->stage[i], wide);
			++i;
		}
	}
	else
		ft_badarg();
}

t_map		*map_singleton(void)
{
	static t_map	*singleton = NULL;

	if (!singleton)
	{
		if ((singleton = (t_map*)malloc(sizeof(t_map))) == NULL)
			return (NULL);
		singleton->tall = 0;
		singleton->wide = 0;
		singleton->stage = NULL;
	}
	return (singleton);
}
