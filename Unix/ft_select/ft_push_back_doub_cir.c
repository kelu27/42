/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_doub_cir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:06:43 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/11 15:22:14 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

t_list	*ft_push_back_doub_cir(t_list **element, char *content)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((new->content = ft_strdup(content)) == NULL)
		return (NULL);
	ft_strcpy(new->content, content);
	new->prev = (*element)->prev;
	new->next = (*element);
	(*element)->prev->next = new;
	(*element)->prev = new;
	(*element)->selected = 0;
	return (*element);
}
