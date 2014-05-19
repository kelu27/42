/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 18:06:53 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 23:09:51 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

char		*ft_prompt(void)
{
	char	pwd[1024];
	char	*str;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	pwd[0] = '\0';
	str = ft_strdup("\033[1;34m[..");
	if (!(tab = ft_strsplit(getcwd(pwd, 1024), '/')))
		return ("\033[1;34m[42sh] $> ");
	j = ((strstrlen(tab) - 3 < 0) ? 0 : (strstrlen(tab) - 3));
	if (!tab[j])
		return ("\033[1;34m[/] $> \033[0m");
	while (tab[i])
	{
		if (i >= j)
			str = join_free(join_free(str, "/"), tab[i]);
		free(tab[i++]);
	}
	free(tab);
	str = join_free(str, "] $> \033[0m");
	if (!str)
		return ("\033[1;34m[42sh] $> \033[0m");
	return (str);
}
