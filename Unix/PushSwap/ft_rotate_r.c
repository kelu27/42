/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 12:01:35 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/29 20:18:21 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

void		ft_rotate_r(t_list **l_a, t_list **l_b, char op_name)
{
	if (op_name == 'a')
	{
		ft_rotate_ra(l_a);
		ft_putstr("ra");
	}
	else if (op_name == 'b')
	{
		ft_rotate_rb(l_b);
		ft_putstr("rb");
	}
	else if (op_name == 'r')
	{
		ft_rotate_rab(l_a, l_b);
		ft_putstr("rr");
	}
}

void	ft_rotate_ra(t_list **l_a)
{
	int		temp;

	temp = (*l_a)->content;
	free(&(*l_a)->content);
	(*l_a) = (*l_a)->next;
	(*l_a) = ft_list_push_back(&(*l_a), temp);
}

void	ft_rotate_rb(t_list **l_b)
{
	int		temp;

	temp = (*l_b)->content;
	free(&(*l_b)->content);
	(*l_b) = (*l_b)->next;
	(*l_b) = ft_list_push_back(&(*l_b), temp);
}

void	ft_rotate_rab(t_list **l_a, t_list **l_b)
{
	ft_rotate_ra(l_a);
	ft_rotate_rb(l_b);
}
