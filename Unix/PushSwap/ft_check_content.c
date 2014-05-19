/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:45:26 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/28 17:17:55 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

int		ft_check_content(t_list *l_a, t_list *l_b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (l_a && l_a->next)
	{
		if (l_a->content < l_a->next->content)
			j++;
		l_a = l_a->next;
		i++;
	}
	if (i == j && l_b == NULL)
		return (2);
	if (i == j)
		return (1);
	return (0);
}
