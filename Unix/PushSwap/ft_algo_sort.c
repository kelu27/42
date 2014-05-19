/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:34:19 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/29 19:19:45 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_push_swap.h"

int		ft_algo_sort(t_list **l_a, t_list **l_b, int j)
{
	while (ft_check_content((*l_a), (*l_b)) != 1)
	{
		if (j > 0)
			write(1, " ", 1);
		if ((*l_a) && (*l_a)->next && ((*l_a)->next->content < (*l_a)->content))
			ft_swap_s(&(*l_a), &(*l_b), 'a');
		else if ((*l_a) && ((*l_a)->content > ft_last_content((*l_a))))
			ft_rotate_r(&(*l_a), &(*l_b), 'a');
		else if ((*l_b) && (*l_b)->next && ((*l_b)->next->content >
					(*l_b)->content))
			ft_swap_s(&(*l_a), &(*l_b), 'b');
		else if ((*l_b) && ((*l_b)->content < ft_last_content((*l_b))))
			ft_rotate_r(&(*l_a), &(*l_b), 'b');
		else if ((*l_a) != NULL)
			ft_take_p(&(*l_a), &(*l_b), 'b');
		j++;
	}
	if (l_b != NULL)
	{
		write(1, " ", 1);
		ft_take_p(&(*l_a), &(*l_b), 'a');
	}
	return (j);
}
