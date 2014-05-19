/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 11:51:20 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/29 19:30:42 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_push_swap.h"

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*l_a;
	t_list	*l_b;

	l_a = NULL;
	l_b = NULL;
	i = 1;
	j = 0;
	if (argc == 1)
		write(2, "Error\n", 6);
	while (i < argc)
	{
		l_a = ft_list_push_back(&l_a, ft_atoi(argv[i]));
		i++;
	}
	while (ft_check_content(l_a, l_b) != 2)
		j = ft_algo_sort(&l_a, &l_b, j);
	write(1, "\n", 1);
	return (0);
}
