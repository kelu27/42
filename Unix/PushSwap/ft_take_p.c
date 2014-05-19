/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:09:37 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/28 17:01:51 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

void		ft_take_p(t_list **l_a, t_list **l_b, char op_name)
{
	if (op_name == 'a')
	{
		ft_take_pa(l_a, l_b);
		ft_putstr("pa");
	}
	else if (op_name == 'b')
	{
		ft_take_pb(l_a, l_b);
		ft_putstr("pb");
	}
}

void		ft_take_pa(t_list **l_a, t_list **l_b)
{
	if ((*l_b) == NULL)
		return ;
	(*l_a) = ft_list_push_front(l_a, (*l_b)->content);
	(*l_b) = (*l_b)->next;
}

void		ft_take_pb(t_list **l_a, t_list **l_b)
{
	if ((*l_a) == NULL)
		return ;
	(*l_b) = ft_list_push_front(l_b, (*l_a)->content);
	(*l_a) = (*l_a)->next;
}
