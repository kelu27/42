/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_underline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 16:14:24 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/11 15:26:51 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "ft_select.h"

void	ft_underline(void)
{
	t_list			*temp;
	t_list			*list;
	t_list			*cursor;
	t_item			*item;

	list = *ft_create2();
	cursor = *ft_create3();
	temp = list->next;
	item = ft_item_init();
	while (temp != list)
	{
		tputs(tgoto(tgetstr("cm", NULL), item->x, item->word), 1, tty_putchar);
		item->word++;
		if (cursor->content == temp->content)
			tputs(tgetstr("us", NULL), 1, tty_putchar);
		if (temp->selected == 1)
			tputs(tgetstr("so", NULL), 1, tty_putchar);
		ft_putstr_fd(temp->content);
		tputs(tgetstr("me", NULL), 1, tty_putchar);
		if (item->line <= item->word)
			item->x = item->x + item->word_lenght;
		item->word = (item->line <= item->word) ? 0 : item->word;
		temp = temp->next;
	}
}
