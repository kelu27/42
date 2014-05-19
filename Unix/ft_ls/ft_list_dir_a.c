/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 17:53:07 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/13 18:45:48 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "./libft/includes/libft.h"

int		ft_list_dir_a(void)
{
	DIR				*directory;
	struct dirent	*diread;

	if ((directory = opendir(".")) == NULL)
		return (0);
	directory = opendir(".");
	while ((diread = readdir(directory)) != NULL)
		ft_putendl(diread->d_name);
	closedir(directory);
	return (0);
}
