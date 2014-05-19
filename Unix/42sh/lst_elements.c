/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:20:27 by jflorimo          #+#    #+#             */
/*   Updated: 2014/03/14 15:26:38 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

t_history	*init_history(void)
{
	t_history	*hist;

	if (!(hist = (t_history *)malloc(sizeof(t_history))))
		ft_error(1, "init_history");
	hist->cmd = NULL;
	hist->prev = NULL;
	hist->next = NULL;
	return (hist);
}

t_history	*add_in_history(t_history *hist, t_list *cmd)
{
	t_history	*new;

	if (!hist)
		hist = init_history();
	if (!(new = (t_history *)malloc(sizeof(t_history))))
		ft_error(1, "add_in_history");
	new->cmd = cmd;
	if (hist->next)
	{
		hist->next->prev = new;
		new->next = hist->next;
	}
	else
		new->next = NULL;
	hist->next = new;
	new->prev = hist;
	return (hist);
}

void		init_list(t_list **list)
{
	t_list		*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		ft_error(1, "init_list");
	new->value = '\0';
	new->prev = NULL;
	new->next = NULL;
	*list = new;
}

char		*lst_to_str(t_list *list)
{
	int		i;
	char	*str;
	t_list	*tmp;

	i = 0;
	tmp = list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	str = ft_strnew(i);
	i = 0;
	while (list->next)
	{
		str[i] = list->value;
		i++;
		list = list->next;
	}
	return (str);
}
