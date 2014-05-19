/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 15:16:28 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/15 21:49:38 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "./libft/includes/libft.h"

int		ft_list_dir(void)
{
	DIR				*directory;
	struct dirent	*diread;
	struct stat		*statlist;
	int				stats;

	directory = NULL;
	diread = NULL;
	statlist = NULL;
	stats = 0;
	if ((statlist = (struct stat*)malloc(sizeof(*statlist))) == NULL)
		return (-1);
	if ((directory = opendir(".")) == NULL)
		return (0);
	while ((diread = readdir(directory)) != NULL)
	{
		stats = stat(diread->d_name, statlist);
		ft_putnbr(statlist->st_size);
		ft_putchar(' ');
		ft_putendl(diread->d_name);
	}
	closedir(directory);
	return (0);
}
