/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:37:40 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 22:07:30 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_path	**ft_create_double_circular(void)
{
	static t_path	*racine = NULL;

	if (racine == NULL)
	{
		if ((racine = (t_path *)malloc(sizeof(t_path))) == NULL)
			return (NULL);
		racine->next = racine;
		racine->prev = racine;
		racine->tube = "luc";
	}
	return (&racine);
}

void	ft_push_back_doub_cir(t_path **element, char *tube)
{
	t_path	*new;

	if ((new = (t_path *)malloc(sizeof(t_path))) == NULL)
		return ;
	new->tube = ft_strdup(tube);
	new->prev = (*element)->prev;
	new->next = (*element);
	(*element)->prev->next = new;
	(*element)->prev = new;
}
