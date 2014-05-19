/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:31:52 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 21:59:59 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	*ft_cut_bef_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ')
		i++;
	str[i] = '\0';
	return (str);
}

int				ft_check_diez(char *line)
{
	if (line[0] == '#')
		return (1);
	return (0);
}

static int	ft_check_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_minus(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void		ft_check_room(t_imput *data, t_map *map)
{
	t_path	*pipe;
	t_room	*room;
	int		i;

	i = 0;
	pipe = *ft_create_double_circular();
	room = *ft_create_double_circular2();
	while (map)
	{
		if (ft_check_diez(map->line) == 0 && ft_check_minus(map->line) == 1)
		{
			ft_push_back_doub_cir(&pipe, map->line);
			i++;
		}
		if (ft_check_diez(map->line) == 0 && ft_check_space(map->line) == 1)
			ft_push_back_doub_cir2(&room, ft_cut_bef_space(map->line));
		map = map->next;
	}
	pipe->count = i;
	data->pathlink = pipe;
	data->room = room;
}
