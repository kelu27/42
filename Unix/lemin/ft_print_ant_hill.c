/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ant_hill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 17:17:20 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 22:08:32 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static void	ft_ants(t_imput *data)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!(data->ants_names = (char **)ft_memalloc(sizeof(char *) *
		data->ant + 1)))
		ft_error();
	while (i <= data->ant)
	{
		data->ants_names[j] = ft_strjoin(ft_strjoin("L", ft_itoa(i)), "-");
		i++;
		j++;
	}
	data->ants_names[j] = '\0';
}

static void	ft_reverse_path(t_imput *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (data->path[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = ft_strdup(data->path[i]);
		data->path[i] = ft_strdup(data->path[j]);
		data->path[j] = ft_strdup(tmp);
		i++;
		j--;
	}
	free(tmp);
}

static void	ft_ant_room2(t_imput *data, int j, int k)
{
	char	*join;

	join = ft_strjoin(data->ants_names[k], data->path[j]);
	if (data->print[j + k] == NULL)
		data->print[j + k] = ft_strdup(join);
	else
	{
		data->print[j + k] = ft_strjoin(data->print[j + k], " ");
		data->print[j + k] = ft_strjoin(data->print[j + k], join);
	}
}

static void	ft_ant_room(t_imput *data)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!(data->print = (char **)malloc(sizeof(char *) *
		(data->ant * (data->count + 1)))))
		ft_error();
	while (k < data->ant)
	{
		while (j < data->count - 1)
		{
			ft_ant_room2(data, j, k);
			i++;
			j++;
		}
		j = 0;
		k++;
	}
	data->print[i] = '\0';
}

void		ft_print_ant_hill(t_imput *data)
{
	int		i;

	i = 0;
	ft_ants(data);
	ft_reverse_path(data);
	ft_ant_room(data);
	while (data->print[i])
	{
		ft_putendl(data->print[i]);
		i++;
	}
}
