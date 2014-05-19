/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 20:01:13 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/14 11:55:22 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "wolf.h"

int				loop_hook(t_env *e)
{
	static clock_t	time = 0;
	clock_t			cur_time;
	double			res;

	XQueryKeymap(e->mlx->display, e->keys);
	key_hook(e);
	cur_time = clock();
	res = (double)(cur_time - time) / CLOCKS_PER_SEC;
	if (res > 0.01)
	{
		wall(e);
		time = clock();
	}
	return (0);
}
