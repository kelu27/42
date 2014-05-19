/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballu <vballu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:40:27 by vballu            #+#    #+#             */
/*   Updated: 2014/03/09 12:16:31 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alcu.h"

void		ft_print_map(void)
{
	int		high;
	int		wide;
	int		i;
	int		j;

	i = 0;
	high = map_singleton()->tall;
	wide = map_singleton()->wide;
	while(i < high)
	{
		j = 0;
		while (j < wide)
		{
			ft_putchar(map_singleton()->stage[i][j]);
			ft_putchar(' ');
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}
