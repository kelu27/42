/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 13:50:19 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/13 13:50:24 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_win, 0, 0);
	return (0);
}

void	floori(t_env *img)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = HEIGHT / 2;
	color = 0x336600;
	while (y <= (HEIGHT))
	{
		if (x == LENGTH)
		{
			x = 0;
			y++;
		}
		while (x < LENGTH)
		{
			mlx_pxl_put_to_img(img, x, y, color);
			x++;
		}
	}
}

void	sky(t_env *img)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = 0x7EC3FF;
	while (y <= (HEIGHT / 2))
	{
		if (x == LENGTH)
		{
			x = 0;
			y++;
		}
		while (x < LENGTH)
		{
			mlx_pxl_put_to_img(img, x, y, color);
			x++;
		}
	}
}
