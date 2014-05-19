/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:13:55 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/01 12:46:49 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
	{
		ft_putchar(s[index]);
		index ++;
	}
}
