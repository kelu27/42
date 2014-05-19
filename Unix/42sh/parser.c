/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 15:11:23 by nschilli          #+#    #+#             */
/*   Updated: 2014/03/26 17:52:02 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int			find_operator(t_token *list)
{
	t_token		*cursor;

	cursor = list;
	while (cursor)
	{
		if (cursor->type < 5)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

t_token		*find_priority(t_token *list)
{
	t_token		*cursor;
	t_token		*prio;

	cursor = list;
	prio = list;
	while (cursor)
	{
		if (cursor->type < prio->type)
			prio = cursor;
		if (cursor->type == 1)
			break ;
		cursor = cursor->next;
	}
	return (prio);
}

t_token		*get_left_op(t_token *list)
{
	t_token	*left_list;
	t_token	*tmp;

	tmp = list;
	left_list = NULL;
	while (tmp != find_priority(list))
	{
		ft_pushback_token(&left_list, ft_newtoken(tmp->name, tmp->type));
		tmp = tmp->next;
	}
	return (left_list);
}

t_tree		*ft_parser(t_token *token)
{
	t_token	*begin;
	t_token	*first;
	t_tree	*tree;

	tree = NULL;
	first = NULL;
	begin = token;
	tree = create_tree(token, NULL);
	(void)first;
	(void)begin;
	return (tree);
}
