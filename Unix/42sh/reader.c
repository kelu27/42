/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 13:58:16 by jflorimo          #+#    #+#             */
/*   Updated: 2014/03/26 19:03:37 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include "shell.h"

void		board_cursor(t_list *cmd, t_list *cursor)
{
	replace_cursor_left(cmd);
	ft_putstr(lst_to_str(cmd));
	replace_cursor(cursor);
}

void		moove_cursor(t_list **cursor, char read_char[5])
{
	if (*(unsigned int *)read_char == 4414235)
	{
		if ((*cursor)->value != '\0')
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			(*cursor) = (*cursor)->next;
		}
		else
			tputs(tgetstr("bl", NULL), 1, tputs_putchar);
	}
	else if (*(unsigned int *)read_char == 4479771)
	{
		if ((*cursor)->prev)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			(*cursor) = (*cursor)->prev;
		}
		else
			tputs(tgetstr("bl", NULL), 1, tputs_putchar);
	}
}

void		history_two(t_history **hist, t_list **cursor, t_list **cmd)
{
	t_list	*temp_save;

	temp_save = NULL;
	if ((*hist) && (*hist)->next)
	{
		if ((*hist) && !(*hist)->prev)
			temp_save = cpy_lst((*cmd));
		(*hist) = (*hist)->next;
		(*cmd) = cpy_lst((*hist)->cmd);
		*cursor = (*cmd);
		while ((*cursor)->next)
			*cursor = (*cursor)->next;
		board_cursor((*cmd), (*cursor));
	}
	else
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
	(void)temp_save;
}

void		history(t_history **hist, t_list **cursor, t_list **cmd)
{
	t_list	*temp_save;

	temp_save = NULL;
	if ((*hist) && (*hist)->prev && (*hist)->prev->prev)
	{
		(*hist) = (*hist)->prev;
		*cmd = cpy_lst((*hist)->cmd);
		*cursor = *cmd;
		while ((*cursor)->next)
			(*cursor) = (*cursor)->next;
		board_cursor((*cmd), (*cursor));
	}
	else if ((*hist) && (*hist)->prev)
	{
		*hist = (*hist)->prev;
		(*cmd) = cpy_lst(temp_save);
		*cursor = *cmd;
		while ((*cursor)->next)
			*cursor = (*cursor)->next;
		board_cursor((*cmd), (*cursor));
	}
	else
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
}

int			reader(char **line, t_data data)
{
	t_list				*cmd;
	t_list				*cursor;
	static t_history	*hist = NULL;

	init_list(&cmd);
	cursor = cmd;
	while (read(0, data.read_char, 4))
	{
		if (RD == 10)
		{
			if (save_line(line, &hist, &cmd) == 1)
				return (1);
			else
				return (0);
		}
		else if (RD == 127 || RD == 2117294875 || RD == 4283163
			|| RD == 4348699 || RD == 4414235 || RD == 4479771
			|| (data.read_char[0] == 0x0C) || (data.read_char[0] == 0x04)
			|| RD == 9 || RD == 4741915 || RD == 4610843)
			board_reader(&hist, &cursor, &cmd, data.read_char);
		else
			display_char(&cursor, &cmd, data.read_char);
		data = reset_readchar(data);
	}
	return (0);
}
