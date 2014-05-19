/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:14:21 by lcharpen          #+#    #+#             */
/*   Updated: 2013/11/20 12:17:43 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
	{
		ft_putchar(s[index]);
		index++;
	}
	ft_putchar('\n');
}
