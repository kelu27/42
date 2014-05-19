/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 13:50:43 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/13 13:50:48 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_wall(t_env *e, int x)
{
	int	i;
	int	h;
	int	color;

	if (e->side == 1)
	{
		if (e->x > e->wall.x)
			color = 0x625D5D;
		else
			color = 0xFFFF00;
	}
	if (e->side == 2)
	{
		if (e->y > e->wall.y)
			color = 0x800517;
		else
			color = 0x2B3856;
	}
	h = (HEIGHT / (1.5 * e->dst));
	i = (HEIGHT / 2 - h);
	while (i < (HEIGHT / 2) + h)
	{
		mlx_pxl_put_to_img(e, x, i, color);
		++i;
	}
}

void	dst_calcul2(t_env *img, int x, int y)
{
	if (img->walltype == 1)
		img->walltype2 = (x > img->x) ? 1 : 0;
	else
		img->walltype2 = (y > img->y) ? 1 : 0;
	img->wall.x = x;
	img->wall.y = y;
}

float	dst_calcul(t_env *img, float x1, float y1)
{
	int			x;
	int			y;
	float		dst;

	dst = 0.01;
	x = img->x + (dst * x1);
	y = img->y + (dst * y1);
	img->walltype = 0;
	img->side = 0;
	while (img->tab[x][y] == 0 && (HEIGHT / (1.5 * dst) > 0.9))
	{
		dst += 0.01;
		x = img->x + (dst * x1);
		if (img->tab[x][y] > 0 && img->side != 2)
			img->side = 1;
		if (img->tab[x][y] != 0)
			img->walltype = 1;
		y = img->y + (dst * y1);
		if (img->tab[x][y] > 0 && img->side != 1)
			img->side = 2;
	}
	dst_calcul2(img, x, y);
	return (dst);
}

void	wall(t_env *img)
{
	float	x1;
	float	y1;
	float	i;
	float	d_angle;
	float	current;

	i = 0;
	d_angle = (M_PI / 3) / LENGTH;
	sky(img);
	floori(img);
	while (i < LENGTH)
	{
		current = img->angle - (M_PI / 6) + (i * d_angle);
		x1 = cos(current);
		y1 = sin(current);
		img->dst = dst_calcul(img, x1, y1) *
		cos((-(M_PI / 6) + (i * d_angle)));
		print_wall(img, i);
		++i;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img_win, 0, 0);
}
