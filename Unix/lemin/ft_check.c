/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 18:18:22 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 21:46:05 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static void	ft_check_start(t_imput *data, t_map *temp)
{
	char	**tab;
	int		i;

	i = 1;
	while (temp)
	{
		if (ft_strcmp(temp->line, "##start") == 0)
		{
			if (!(tab = (char**)malloc(sizeof(char *) * 3)))
				return ;
			tab = ft_strsplit(temp->next->line, ' ');
			while (tab[i])
				i++;
			if (tab[1] && tab[2] && ft_isdigit(tab[1][0]) == 1 &&
				ft_isdigit(tab[2][0]) == 1)
				data->start = ft_strdup(tab[0]);
			else
				ft_error();
			free(tab);
		}
		temp = temp->next;
	}
	if (i == 1 || i > 3)
		ft_error();
}

static void	ft_check_end(t_imput *data, t_map *temp)
{
	char	**tab;
	int		i;

	i = 1;
	while (temp)
	{
		if (ft_strcmp(temp->line, "##end") == 0)
		{
			if (!(tab = (char**)malloc(sizeof(char *) * 3)))
				return ;
			tab = ft_strsplit(temp->next->line, ' ');
			while (tab[i])
				i++;
			if (tab[1] && tab[2] && ft_isdigit(tab[1][0]) == 1 &&
				ft_isdigit(tab[2][0]) == 1)
				data->end = ft_strdup(tab[0]);
			else
				ft_error();
			free(tab);
		}
		temp = temp->next;
	}
	if (i == 1 || i > 3)
		ft_error();
}

static void	ft_check_ant(t_imput *data, t_map *map)
{
	while (ft_check_diez(map->line) == 1)
		map = map->next;
	if (ft_isdigit(map->line[0]) != 1)
		ft_error();
	else
		data->ant = ft_atoi(map->line);
}

void		ft_check(t_imput *data, t_map *map)
{
	ft_check_ant(data, map);
	ft_check_start(data, map);
	ft_check_end(data, map);
	ft_check_room(data, map);
}
