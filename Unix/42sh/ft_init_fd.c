/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 11:31:02 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/14 14:52:31 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

t_fd	*ft_init_fd(void)
{
	t_fd	*fd;

	if (!(fd = (t_fd *)malloc(sizeof(t_fd))))
		ft_error(1, "ft_init_fd");
	fd->fdin = 0;
	fd->fdout = 1;
	return (fd);
}
