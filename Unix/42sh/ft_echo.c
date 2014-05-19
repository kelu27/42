/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:40:59 by jflorimo          #+#    #+#             */
/*   Updated: 2014/03/27 21:13:00 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

void			ft_echo_scan(char **av, int i, t_fd *fd)
{
	while (av[i])
	{
		if (!av[i + 1])
		{
			echo_option(av[1], av[i], fd);
			break ;
		}
		ft_putstr_fd(av[i], fd->fdout);
		ft_putstr_fd(" ", fd->fdout);
		i++;
	}
}

int				ft_echo(char **av, t_fd *fd)
{
	int		i;

	i = 1;
	if (fd->fdin != 0)
		dup2(fd->fdin, 0);
	if (!av[i])
		ft_putstr_fd("\n", fd->fdout);
	if (ft_strequ(av[i], "-n"))
		i++;
	ft_echo_scan(av, i, fd);
	if (fd->fdout != 1)
		close(fd->fdout);
	if (fd->fdin != 0)
		close(fd->fdin);
	return (1);
}
