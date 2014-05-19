/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:45:35 by jgil              #+#    #+#             */
/*   Updated: 2014/03/14 15:31:05 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

int			save_line_checker(t_list *list)
{
	while (list)
	{
		if (ft_isprint(list->value))
		{
			if (list->value != ' ' && list->value != '	')
				return (1);
		}
		list = list->next;
	}
	return (0);
}

t_list		*cpy_lst(t_list	*hist)
{
	t_list	*cmd;
	t_list	*cursor;

	if (!(cmd = (t_list *)malloc(sizeof(t_list))))
		ft_error(1, "cpy_lst");
	cmd->value = '\0';
	cmd->prev = NULL;
	cmd->next = NULL;
	cursor = cmd;
	while (hist && hist->value != '\0')
	{
		cmd = insert_char(&cursor, hist->value);
		hist = hist->next;
	}
	return (cmd);
}
