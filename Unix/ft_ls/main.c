/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 19:17:39 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/15 21:49:50 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	if (argc == 1 || argv[0])
		ft_list_dir();
	if (argc > 1)
		ft_list_dir_a();
	return (0);
}
