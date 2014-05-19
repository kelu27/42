/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 21:35:07 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 21:12:31 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "./libft/includes/libft.h"

int		main()
{
	t_imput	*data;
	t_map	*map;
	char	*line;

	if (!(data = (t_imput *)malloc(sizeof(t_imput))))
		ft_error();
	if (get_next_line(0, &line) == 0)
		ft_error();
	map = ft_create_elem(line);
	ft_putendl(line);
	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		map = ft_list_push_back(&map, line);
	}
	ft_check(data, map);
	ft_find_path(data);
	ft_print_ant_hill(data);
	return (0);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
