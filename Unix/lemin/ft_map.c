/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 14:59:53 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 22:05:24 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_map	*ft_create_elem(char *line)
{
	t_map	*tmp;

	if (!(tmp = (t_map *)malloc(sizeof(t_map))))
		ft_error();
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->line = line;
	return (tmp);
}

t_map	*ft_list_push_back(t_map **begin_list, char *line)
{
	t_map	*new;
	t_map	*tmp;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	tmp = *begin_list;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->line = ft_strdup(line);
		new->next = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
		ft_create_elem(line);
	return (*begin_list);
}
