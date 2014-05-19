/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 09:30:03 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/10 12:08:02 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_word_lenght(t_list *list)
{
	t_list				*temp;
	unsigned int		i;

	i = 0;
	temp = list->next;
	while (temp != list)
	{
		if (ft_strlen(temp->content) > i)
				i = ft_strlen(temp->content);
		temp = temp->next;
	}
	return (i + 1);
}
