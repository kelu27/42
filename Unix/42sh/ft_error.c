/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:38:02 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/14 14:57:55 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdlib.h>

void	ft_error(int n, char *where)
{
	if (n == 1)
	{
		ft_putstr_fd("42sh malloc error in: ", 2);
		ft_putendl(where);
		exit(2);
	}
}
