/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 21:55:32 by elivet            #+#    #+#             */
/*   Updated: 2014/03/26 17:20:41 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*new_line(char *str, t_list *line)
{
	char	*new;

	new = lst_to_str(line);
	str = ft_strjoin(str, new);
	return (str);
}

void		echo_option(char *first, char *av, t_fd *fd)
{
	if (ft_strequ(first, "-n"))
	{
		ft_putstr_fd(av, fd->fdout);
		ft_putendl_fd("\033[7m%\033[0m", fd->fdout);
	}
	else
	{
		ft_putstr_fd(av, fd->fdout);
		ft_putendl("");
	}
}
