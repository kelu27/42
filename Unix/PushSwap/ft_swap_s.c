/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 18:38:32 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/28 19:24:12 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

void		ft_swap_s(t_list **l_a, t_list **l_b, char op_name)
{

	if (op_name == 'a')
	{
		ft_swap_sa(l_a);
		ft_putstr("sa");
	}
	else if (op_name == 'b')
	{
		ft_swap_sb(l_b);
		ft_putstr("sb");
	}
	else if (op_name == 's')
	{
		ft_swap_ss(l_a, l_b);
		ft_putstr("ss");
	}
}

void		ft_swap_sa(t_list **l_a)
{
	int	tmp;

	if ((*l_a) == NULL || (*l_a)->next == NULL)
		return ;
	tmp = (*l_a)->next->content;
	(*l_a)->next->content = (*l_a)->content;
	(*l_a)->content = tmp;
}

void		ft_swap_sb(t_list **l_b)
{
	int	tmp;

	if ((*l_b) == NULL || (*l_b)->next == NULL)
		return ;
	tmp = (*l_b)->next->content;
	(*l_b)->next->content = (*l_b)->content;
	(*l_b)->content = tmp;
}

void		ft_swap_ss(t_list **l_a, t_list **l_b)
{
	ft_swap_sa(l_a);
	ft_swap_sb(l_b);
}
