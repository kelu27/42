/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 09:03:47 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 22:01:45 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static void		ft_find_path4(t_imput *data)
{
	int	stop;

	stop = 0;
	data->tab = ft_strsplit(data->pathlink->tube, '-');
	if (!(data->tab[0]) || !(data->tab[1]))
	{
		data->pathlink = data->pathlink->next;
		ft_memdel((void **)data->tab);
		while (ft_strcmp(data->pathlink->tube, "luc") == 0)
		{
			stop++;
			data->pathlink = data->pathlink->next;
			if (stop > 5)
				ft_error();
		}
		ft_putendl(data->pathlink->tube);
		data->tab = ft_strsplit(data->pathlink->tube, '-');
	}
}

static char		*ft_find_path2(char *temp, t_imput *data)
{
	int		i;

	i = 0;
	if (!(data->tab = (char **)malloc(sizeof(char *) * 3)))
		ft_error();
	while (ft_strcmp(data->pathlink->tube, "luc") != 0)
		data->pathlink = data->pathlink->next;
	data->pathlink = data->pathlink->next;
	while (i < 2)
	{
		ft_find_path4(data);
		if (ft_strcmp(data->tab[0], temp) == 0 && ft_path_exist(data->tab[1],
			data) == 0)
			return (data->tab[1]);
		else if (ft_strcmp(data->tab[1], temp) == 0 &&
			ft_path_exist(data->tab[0], data) == 0)
			return (data->tab[0]);
		data->pathlink = data->pathlink->next;
		if (ft_strcmp(data->pathlink->tube, "luc") == 0)
		{
			data->pathlink = data->pathlink->next;
			i++;
		}
	}
	return (NULL);
}

static void		ft_find_path3(t_imput *data)
{
	if (data->temp != NULL)
	{
		data->lastpath = data->pathlink;
		ft_save_path(data->temp2, data);
	}
	else if (data->temp == NULL)
	{
		ft_del_path(data);
		ft_memdel((void **)data->path);
		ft_memdel((void **)data->lastpath);
		data->count = 1;
		if(!(data->path = (char **)ft_memalloc(sizeof(char *) *
			data->pathlink->count + 1)))
			ft_error();
		data->temp = ft_strdup(data->end);
	}
}

void			ft_find_path(t_imput *data)
{
	data->pathlink = data->pathlink->next;
	data->count = 1;
	if(!(data->path = (char **)malloc(sizeof(char *) *
		data->pathlink->count + 1)))
		ft_error();
	data->temp2 = ft_strdup(data->end);
	data->temp = ft_find_path2(data->temp2, data);
	if (data->temp == NULL)
		ft_error();
	while (ft_strcmp(data->temp, data->start) != 0)
	{
		if (ft_strcmp(data->pathlink->tube, "luc") == 0)
			data->pathlink = data->pathlink->next;
		data->temp2 = ft_strdup(data->temp);
		data->temp = ft_find_path2(data->temp, data);
		ft_find_path3(data);
		data->path[data->count] = '\0';
		data->pathlink = data->pathlink->next;
		if (ft_strcmp(data->pathlink->tube, "luc") == 0)
			data->pathlink = data->pathlink->next;
	}
}
