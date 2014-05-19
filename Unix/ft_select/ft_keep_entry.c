/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 15:44:19 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/09 10:37:39 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_keep_entry(t_list **l_a, char *buf)
{
	t_list	*temp;

	temp = (*l_a)->next;
	if (buf[0] == 10 && buf[1] == 0)
	{
		while (temp != (*l_a))
		{
			if (temp->selected == 1)
			{
				ft_putstr(temp->content);
				ft_putstr(" ");
			}
			temp = temp->next;
		}
	}
}
