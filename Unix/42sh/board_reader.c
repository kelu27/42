/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 12:15:02 by nschilli          #+#    #+#             */
/*   Updated: 2014/03/26 22:38:40 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include "shell.h"

static void	display_char_only(t_list **cursor, t_list **cmd, char mchar)
{
	write(1, &mchar, 1);
	(*cmd) = insert_char(cursor, mchar);
	board_cursor((*cmd), (*cursor));
}

void		board_reader(t_history **hist, t_list **cursor,
	t_list **cmd, char read_char[5])
{
	if (read_char[0] == 0x0C)
		display_prompt(cursor, cmd);
	else if (read_char[0] == 0x04)
	{
		term_close(ft_init_term());
		exit(0);
	}
	else if (*(unsigned int *)read_char == 9)
		display_char_only(cursor, cmd, ' ');
	else if (*(unsigned int *)read_char == 127
		|| (*(unsigned int *)read_char == 2117294875))
		delete_cursor(cursor, cmd, read_char);
	else if (*(unsigned int *)read_char == 4283163)
		history_two(hist, cursor, cmd);
	else if (*(unsigned int *)read_char == 4348699)
		history(hist, cursor, cmd);
	else if (*(unsigned int *)read_char == 4414235
		|| (*(unsigned int *)read_char == 4479771))
		moove_cursor(cursor, read_char);
}
