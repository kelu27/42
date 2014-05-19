/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 19:36:24 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 22:06:34 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void	ft_del_path(t_imput *data)
{
	t_path	*new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		ft_error();
	new->tube = ft_strdup("luc");
	new->next = new;
	while (ft_strcmp(data->pathlink->tube, "luc") != 0)
	{
		if (ft_strcmp(data->pathlink->tube, data->lastpath->tube) != 0)
			ft_lstaddtail(&new, data->pathlink->tube, "luc");
		data->pathlink = data->pathlink->next;
	}
	data->pathlink = new;
}

void	ft_save_path(char *tube, t_imput *data)
{
	if (data->count == 1)
		data->path[0] = ft_strdup(data->end);
	data->path[data->count] = ft_strdup(tube);
	data->count = data->count + 1;
}

int		ft_path_exist(char *check, t_imput *data)
{
	int	i;

	i = 0;
	if (data->count != 1)
	{
		while (data->path[i])
		{
			if (ft_strcmp(data->path[i], check) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}

