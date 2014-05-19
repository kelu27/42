/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 13:13:46 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/21 20:29:21 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

static void	ft_color(t_env *e, t_coord p, int x, int y)
{
	e->color = 0xFFFFFF;
	if (e->tab[y][x] == 10)
		e->color = 0xFF0000;
	if ((e->tab[y][x + 1] == 10 && e->tab[y][x] != 10)
		|| (e->tab[y][x] == 10 && e->tab[y][x + 1] != 10))
		e->color = 0x0000FF;
	ft_line(&p, calcx(x + 1, y), calcy(x + 1, y, e->tab[y][x + 1]), e);
	if (e->tab[y][x] == 10)
		e->color = 0xFF0000;
	if (e->tab[y + 1][x] != 10 && e->tab[y][x] != 10)
		e->color = 0xFFFFFF;
	if ((e->tab[y + 1][x] == 10 && e->tab[y][x] != 10)
		|| (e->tab[y][x] == 10 && e->tab[y + 1][x] != 10))
		e->color = 0x0000FF;
	ft_line(&p, calcx(x, y + 1), calcy(x, y + 1, e->tab[y + 1][x]), e);
}

void		ft_director(int x, int y, t_env *e)
{
	t_coord		p;

	p.x = calcx(x, y);
	p.y = calcy(x, y, e->tab[y][x]);
	e->color = 0xFFFFFF;
	if (e->tab[y][x] == 10)
		e->color = 0xFF0000;
	mlx_pixel_put(e->mlx, e->win, p.x, p.y, e->color);
	if (x + 1 == e->tab[y][0] && y + 1 != e->numline)
		ft_line(&p, calcx(x, y + 1), calcy(x, y + 1, e->tab[y + 1][x]), e);
	else if (y + 1 == e->numline && x + 1 != e->tab[y][0])
		ft_line(&p, calcx(x + 1, y), calcy(x + 1, y, e->tab[y][x + 1]), e);
	else if (y + 1 != e->numline && x + 1 != e->tab[y][0])
		ft_color(e, p, x, y);
}

void		draw_square(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < e->numline)
	{
		x = 1;
		while (x < e->tab[y][0])
		{
			ft_director(x, y, e);
			x++;
		}
		y++;
	}
}
