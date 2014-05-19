/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:24:34 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/26 18:12:28 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

t_list	*delete_char(t_list	**cursor)
{
	t_list	*temp;

	temp = *cursor;
	if (temp->value != '\0')
	{
		*cursor = (*cursor)->next;
		temp->next->prev = temp->prev;
		if (temp->prev)
			temp->prev->next = temp->next;
		free(temp);
	}
	temp = *cursor;
	while (temp && temp->prev)
		temp = temp->prev;
	return (temp);
}

t_list	*backspace_char(t_list **cursor)
{
	t_list	*temp;

	temp = *cursor;
	if (temp->prev)
	{
		temp = temp->prev;
		temp->next->prev = temp->prev;
		if (temp->prev)
			temp->prev->next = temp->next;
		free(temp);
	}
	temp = *cursor;
	while (temp && temp->prev)
		temp = temp->prev;
	return (temp);
}

t_list	*insert_char(t_list **cursor, char value)
{
	t_list		*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		ft_error(1, "insert_char");
	new->value = value;
	if ((*cursor)->prev)
		(*cursor)->prev->next = new;
	new->prev = (*cursor)->prev;
	(*cursor)->prev = new;
	new->next = *cursor;
	while (new->prev)
		new = new->prev;
	return (new);
}
