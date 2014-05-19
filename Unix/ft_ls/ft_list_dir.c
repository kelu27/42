/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 10:37:27 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/13 20:57:51 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "./libft/includes/libft.h"

int		ft_list_dir(void)
{
	DIR				*directory;
	struct dirent	*diread;

	if ((directory = opendir(".")) == NULL)
		return (0);
	directory = opendir(".");
	while ((diread = readdir(directory)) != NULL)
	{
		if (diread->d_name[0] != '.')
			ft_putendl(diread->d_name);
	}
	closedir(directory);
	return (0);
}
