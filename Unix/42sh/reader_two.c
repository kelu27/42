/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 17:08:56 by nschilli          #+#    #+#             */
/*   Updated: 2014/03/26 17:49:34 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include "shell.h"

t_data	reset_readchar(t_data data)
{
	data.read_char[0] = 0;
	data.read_char[1] = 0;
	data.read_char[2] = 0;
	data.read_char[3] = 0;
	data.read_char[4] = 0;
	return (data);
}

void	delete_cursor(t_list **cursor, t_list **cmd, char read_char[5])
{
	if (*(unsigned int *)read_char == 127)
	{
		(*cmd) = backspace_char(cursor);
		board_cursor((*cmd), (*cursor));
	}
	else if (*(unsigned int *)read_char == 2117294875)
	{
		(*cmd) = delete_char(cursor);
		board_cursor((*cmd), (*cursor));
	}
}

void	display_char(t_list **cursor, t_list **cmd, char read_char[5])
{
	ft_putstr(read_char);
	(*cmd) = insert_char(cursor, read_char[0]);
	board_cursor((*cmd), (*cursor));
}

void	display_prompt(t_list **cursor, t_list **cmd)
{
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	ft_putstr(ft_prompt());
	init_list(cmd);
	(*cursor) = (*cmd);
}

int		save_line(char **line, t_history **hist, t_list **cmd)
{
	while ((*hist) && (*hist)->prev)
		(*hist) = (*hist)->prev;
	if (save_line_checker(*cmd))
		(*hist) = add_in_history((*hist), (*cmd));
	else
		return (0);
	*line = lst_to_str((*cmd));
	return (1);
}
