/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 18:44:24 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/21 18:47:03 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

int			absolute(int x)
{
	if (x < 0)
		x = x * (-1);
	return (x);
}

void		swap_int(int *x, int *y)
{
	int	t;

	t = *x;
	*x = *y;
	*y = t;
}

static void	draw_line(t_coord *p, int x2, int y2, t_env *e)
{
	t_line	l;

	l.xincr = (x2 > p->x ? 1 : -1);
	l.dy = y2 - p->y;
	l.dx = absolute(x2 - p->x);
	l.d = 2 * l.dx - l.dy;
	l.aincr = 2 * (l.dx - l.dy);
	l.bincr = 2 * l.dx;
	l.x = p->x;
	l.y = p->y;
	mlx_pixel_put(e->mlx, e->win, l.x, l.y, e->color);
	l.y = p->y + 1;
	while (l.y <= y2)
	{
		if (l.d >= 0)
		{
			l.x += l.xincr;
			l.d += l.aincr;
		}
		else
			l.d += l.bincr;
		mlx_pixel_put(e->mlx, e->win, l.x, l.y, e->color);
		l.y++;
	}
}

static void	draw_line_bis(t_coord *p, int x2, int y2, t_env *e)
{
	t_line	l;

	l.yincr = (y2 > p->y ? 1 : -1);
	l.dx = x2 - p->x;
	l.dy = absolute(y2 - p->y);
	l.d = 2 * l.dy - l.dx;
	l.aincr = 2 * (l.dy - l.dx);
	l.bincr = 2 * l.dy;
	l.x = p->x;
	l.y = p->y;
	mlx_pixel_put(e->mlx, e->win, l.x, l.y, e->color);
	l.x = p->x + 1;
	while (l.x <= x2)
	{
		if (l.d >= 0)
		{
			l.y += l.yincr;
			l.d += l.aincr;
		}
		else
			l.d += l.bincr;
		mlx_pixel_put(e->mlx, e->win, l.x, l.y, e->color);
		l.x++;
	}
}

void		ft_line(t_coord *p, int x2, int y2, t_env *e)
{
	if (absolute(x2 - p->x) < absolute(y2 - p->y))
	{
		if (p->y > y2)
		{
			swap_int(&p->x, &x2);
			swap_int(&p->y, &y2);
		}
		draw_line(p, x2, y2, e);
	}
	else
	{
		if (p->x > x2)
		{
			swap_int(&p->x, &x2);
			swap_int(&p->y, &y2);
		}
		draw_line_bis(p, x2, y2, e);
	}
}
