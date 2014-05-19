/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 20:34:55 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/27 13:58:43 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

t_list	*ft_list_push_front(t_list **begin_list, int content)
{
	t_list		*new_data;

	new_data = NULL;
	new_data = ft_create_elem(content);
	if (*begin_list == NULL)
		new_data->next = NULL;
	else
		new_data->next = *begin_list;
		*begin_list = new_data;
	return (*begin_list);
}
