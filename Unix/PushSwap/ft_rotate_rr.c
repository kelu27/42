/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 14:13:48 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/28 18:47:40 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_push_swap.h"

void		ft_rotate_rr(t_list **l_a, t_list **l_b, char op_name)
{
	if (op_name == 'a')
	{
		ft_rotate_rra(l_a);
		ft_putstr("rra");
	}
	else if (op_name == 'b')
	{
		ft_rotate_rrb(l_b);
		ft_putstr("rrb");
	}
	else if (op_name == 'r')
	{
		ft_rotate_rrr(l_a, l_b);
		ft_putstr("rrr");
	}
}

void		ft_rotate_rra(t_list **l_a)
{
	int		temp;
	t_list	*tmp;

	tmp = (*l_a);
	while (tmp->next->next)
		tmp = tmp->next;
	temp = tmp->next->content;
	tmp->next = NULL;
	(*l_a) = ft_list_push_front(l_a, temp);
}

void		ft_rotate_rrb(t_list **l_b)
{
	int		temp;
	t_list	*tmp;

	tmp = (*l_b);
	while (tmp->next->next)
		tmp = tmp->next;
	temp = tmp->next->content;
	tmp->next = NULL;
	(*l_b) = ft_list_push_front(l_b, temp);
}

void		ft_rotate_rrr(t_list **l_a, t_list **l_b)
{
	ft_rotate_rra(l_a);
	ft_rotate_rrb(l_b);
}
