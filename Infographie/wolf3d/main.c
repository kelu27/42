/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:53:03 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/18 23:03:01 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		mlx_pxl_put_to_img(t_env *img, int x, int y, int color)
{
	if (img->data != NULL && x >= 0 && x <= LENGTH && y >= 0 && y <= HEIGHT)
		ft_memcpy(&img->data[(x * 4) + (y * 4 * LENGTH)], &color, 4);
	return (0);
}

void	move_able(t_env *e, float x, float y)
{
	int			a;
	int			b;

	a = x;
	b = y;
	if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && e->tab[a][b] == 0)
	{
		e->x = x;
		e->y = y;
	}
	wall(e);
}

int		ft_wolf(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	e->win = mlx_new_window(e->mlx, LENGTH, HEIGHT, "wolf 3D");
	if (e->win == NULL)
		return (EXIT_FAILURE);
	e->img_win = mlx_new_image(e->mlx, LENGTH, HEIGHT);
	e->data =
	mlx_get_data_addr(e->img_win, &(e->bitpp), &(e->size_l), &(e->endian));
	e->x = 13.5;
	e->y = 1.5;
	e->angle = M_PI;
	e->dst = -1;
	wall(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
	mlx_put_image_to_window(e->mlx, e->win, e->img_win, 0, 0);
	return (EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	char	**map;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (!(e->keys = (char *)malloc(sizeof(char))))
		return (0);
	if (argc == 2)
	{
		map = ft_strsplit(argv[1], '.');
		if (!map[1])
		{
			ft_putendl("Bad map file type");
			return (0);
		}
		if (ft_strcmp(map[1], "w") != 0)
		{
			ft_putendl("Bad map file type");
			return (0);
		}
		fill_in_tab(argv[1], e);
		ft_wolf(e);
	}
	return (0);
}
