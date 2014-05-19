/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 11:56:10 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/14 11:56:19 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_hook2(t_env *e, float x, float y)
{
	if (e->keys[1] == 1 || e->keys[1] == 3 || e->keys[16] == 8
		|| e->keys[16] == 72 || e->keys[16] == 40)
		e->angle -= (M_PI / 60);
	else if (e->keys[1] == 4 || e->keys[1] == 6 || e->keys[16] == 16
		|| e->keys[16] == 80 || e->keys[16] == 48)
		e->angle += (M_PI / 60);
	if (e->keys[2] == 32 || e->keys[16] == 64 || e->keys[16] == 80
		|| e->keys[16] == 72)
	{
		x += e->x;
		y += e->y;
	}
	else if (e->keys[1] == 2 || e->keys[1] == 6 || e->keys[1] == 3
		|| e->keys[16] == 32 || e->keys[16] == 40 || e->keys[16] == 48)
	{
		x = e->x - x;
		y = e->y - y;
	}
	move_able(e, x, y);
}

void	key_hook(t_env *e)
{
	float	x;
	float	y;

	y = (0.2 * sin(e->angle));
	x = (0.2 * cos(e->angle));
	if (e->keys[7] == 32)
		exit(0);
	else
		key_hook2(e, x, y);
}
