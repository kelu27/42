/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballu <vballu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:34:33 by vballu            #+#    #+#             */
/*   Updated: 2014/03/08 21:48:06 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "alcu.h"

//static int random_player()
//{
//	return (rand() % (3 - 1) + 1);
//}

int		main(int argc, char **argv)
{
	char	*line;

	if (argc != 3)
	{
		ft_badarg();
		return (0);
	}
	else
	{
		ft_create_map(argv[1], argv[2]);
		ft_print_map();
		while (42)
		{
			ft_putstr("Column number: ");
			if (get_next_line(0, &line) == 0)
				return (0);
			if (ft_putoken(argv[1], argv[2], line) == 1)
				return (0);
			ft_putendl("IA play");
			if (get_next_line(0, &line) == 0)
				return (0);
			if (ft_putoken2(argv[1], argv[2], line) == 1)
				return (0);
		}
	}
	return (0);
}
