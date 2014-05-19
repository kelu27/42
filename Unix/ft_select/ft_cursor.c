/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 14:37:28 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/10 13:47:11 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_cursor(t_list **cursor, char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
	{
		if ((*cursor)->next->content != NULL)
			(*cursor) = (*cursor)->next;
		else
			(*cursor) = (*cursor)->next->next;
	}
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
	{
		if ((*cursor)->prev->content != NULL)
			(*cursor)= (*cursor)->prev;
		else
			(*cursor) = (*cursor)->prev->prev;
	}
}
