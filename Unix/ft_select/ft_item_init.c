/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 17:04:24 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/11 15:22:12 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "ft_select.h"

t_item	*ft_item_init(void)
{
	t_item			*item;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	if ((item = (t_item *)malloc(sizeof(t_item))) == NULL)
		return (NULL);
	item->word_lenght = ft_word_lenght(*ft_create2());
	item->word = 0;
	item->line = win.ws_row;
	item->col = win.ws_col;
	item->x = 0;
	return (item);
}
