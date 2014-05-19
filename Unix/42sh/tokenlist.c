/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 17:01:23 by nschilli          #+#    #+#             */
/*   Updated: 2014/03/26 17:43:11 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

t_token		*ft_newtoken(char *name, int type)
{
	t_token	*newtoken;

	if (!(newtoken = (t_token *)malloc(sizeof(t_token))))
		ft_error(1, "ft_newtoken");
	if (newtoken == NULL)
		return (NULL);
	else
	{
		newtoken->name = ft_strtrim(name);
		newtoken->type = type;
		newtoken->next = NULL;
		newtoken->prev = NULL;
	}
	return (newtoken);
}

void		ft_pushback_token(t_token **list_token, t_token *newtoken)
{
	t_token	*temp;

	temp = *list_token;
	if (temp == NULL)
		*list_token = newtoken;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newtoken;
		newtoken->prev = temp;
	}
}
