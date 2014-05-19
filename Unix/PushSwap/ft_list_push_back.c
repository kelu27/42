/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 16:18:10 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/28 19:21:54 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

t_list		*ft_list_push_back(t_list **begin_list, int content)
{
	t_list		*new_data;
	t_list		*tmp;

	tmp = *begin_list;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		new_data = ft_create_elem(content);
		tmp->next = new_data;
	}
	else
		*begin_list = ft_create_elem(content);
	return (*begin_list);
}
