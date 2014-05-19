/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:11:15 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 22:03:23 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

static	t_path	*ft_lstnew2(char *data)
{
	t_path	*new;

	new = (t_path *)malloc(sizeof(t_path));
	if (new)
		new->tube = ft_strdup(data);
	return (new);
}

void	ft_lstaddtail(t_path **list, char *content, char *start)
{
	t_path	*new;
	t_path	*tmp;

	new = ft_lstnew2(content);
	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	new->next = tmp;
	while (ft_strcmp(start, tmp->next->tube) != 0)
		tmp = tmp->next;
	tmp->next = new;
}
