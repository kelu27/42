/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:30:33 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 22:09:27 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_room	**ft_create_double_circular2(void)
{
	static t_room	*racine = NULL;

	if (racine == NULL)
	{
		if ((racine = (t_room *)malloc(sizeof(t_room))) == NULL)
			return (NULL);
		racine->next = racine;
		racine->prev = racine;
		racine->room= NULL;
	}
	return (&racine);
}

void	ft_push_back_doub_cir2(t_room **element, char *tube)
{
	t_room	*new;

	if ((new = (t_room *)malloc(sizeof(t_room))) == NULL)
		return ;
	new->room = ft_strdup(tube);
	new->prev = (*element)->prev;
	new->next = (*element);
	(*element)->prev->next = new;
	(*element)->prev = new;
}
