/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 13:08:25 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/21 13:23:31 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

static void	display(t_env *e)
{
	draw_square(e);
}

static int	expose_hook(t_env *e)
{
	display(e);
	return (0);
}

static int	key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

void		draw(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1500, 1200, "fdf");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
