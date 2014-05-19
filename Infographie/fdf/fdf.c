/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 17:40:40 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/21 18:48:39 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"
#include "./libft/includes/libft.h"

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		fill_in_tab(argv[1], &e);
		draw(&e);
	}
	return (0);
}
