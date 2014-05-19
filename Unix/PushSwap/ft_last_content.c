/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:05:02 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/28 19:21:03 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_push_swap.h"

int		ft_last_content(t_list *test)
{
	int	temp;

	temp = 0;
	while (test && test->next && test->next->next)
		test = test->next;
	if (test->next == NULL)
		temp = test->content;
	else
		temp = test->next->content;
	return (temp);
}
