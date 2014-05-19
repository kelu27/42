/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_implementation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 12:15:32 by jflorimo          #+#    #+#             */
/*   Updated: 2014/03/04 14:32:06 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <termcap.h>
#include "shell.h"

void	replace_cursor_left(t_list *cursor)
{
	t_list	*tmp;
	char	*prompt;
	int		i;

	tmp = cursor;
	prompt = ft_prompt();
	i = 0;
	tputs(tgetstr("dl", NULL), 1, tputs_putchar);
	while (tmp->next != NULL)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		tmp = tmp->next;
	}
	while (prompt[i] != '\0')
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		i++;
	}
	while (i > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		i--;
	}
	ft_putstr(ft_prompt());
}

void	replace_cursor(t_list *cursor)
{
	t_list	*tmp;

	tmp = cursor;
	while (tmp->next != NULL)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		tmp = tmp->next;
	}
}

void	replace_cursor_right(t_list *cursor)
{
	t_list	*tmp;

	tmp = cursor;
	while (tmp->next != NULL)
	{
		tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		tmp = tmp->next;
	}
}
