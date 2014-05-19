/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_select.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 14:16:23 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/08 15:22:44 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_cursor_select(t_list **cursor, char *buf)
{
	if (buf[0] == 32 && buf[1] == 0)
	{
		if ((*cursor)->selected == 0)
			(*cursor)->selected = 1;
		else if ((*cursor)->selected == 1)
			(*cursor)->selected = 0;
		if ((*cursor)->next->content != NULL)
			(*cursor) = (*cursor)->next;
		else
			(*cursor) = (*cursor)->next->next;
	}
}
