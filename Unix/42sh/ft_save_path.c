/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:36:57 by lcharpen          #+#    #+#             */
/*   Updated: 2014/02/19 17:17:40 by jgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

/*
** Is used to save the PATH at the beginning of the shell
** and return it when the PATH isn't found in env
** The static 'done' shows if the saving has been done
** if not, save_path will return NULL
*/

char	*save_path(char **env, int n)
{
	static char	*path;
	static int	done = 0;

	if (n == 0)
	{
		if (!(path = ft_strdup(get_in_env(env, "PATH="))))
			return (NULL);
		done = 1;
	}
	else if (n == 1 && done == 1)
		return (path);
	return (NULL);
}
