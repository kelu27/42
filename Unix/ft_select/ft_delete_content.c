/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 16:53:21 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/10 13:07:59 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

void	ft_delete_content(t_list **cursor, char *buf)
{
	if ((buf[0] == 127 || buf[0] == 126) && buf[1] == 0)
	{
		(*cursor)->prev->next = (*cursor)->next;
		(*cursor)->next->prev = (*cursor)->prev;
		if ((*cursor)->next->content != NULL)
			(*cursor) = (*cursor)->next;
		else
			(*cursor) = (*cursor)->next->next;
	}
}

