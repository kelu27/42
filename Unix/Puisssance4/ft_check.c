/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:58:06 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/09 12:15:40 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int	ft_check_line(int maxcol, int line)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (i <= maxcol)
	{
		if (map_singleton()->stage[line][i] == 'X' && map_singleton()->stage[line][i + 1] != '0')
		{
			w++;
			i++;
			if (w == 4)
			{
				ft_putendl("you win line");
				return (1);
			}
		}
		else if (map_singleton()->stage[line][i] == '0' && map_singleton()->stage[line][i + 1] != 'X')
		{
			w++;
			i++;
			if (w == 4)
			{
				ft_putendl("IA win line");
				return (1);
			}
		}
		else
		{
			w = 0;
			i++;
		}
	}
	return (0);
}

static int	ft_check_col(int maxline, int col)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (i < maxline)
	{
		if (i + 1 < maxline && map_singleton()->stage[i][col] == 'X' && map_singleton()->stage[i + 1][col] != '0')
		{
			w++;
			i++;
			if (w == 4)
			{
				ft_putendl("you win col");
				return (1);
			}
		}
		else if (i + 1 < maxline  && map_singleton()->stage[i][col] == '0' && map_singleton()->stage[i + 1][col] != 'X')
		{
			w++;
			i++;
			if (w == 4)
			{
				ft_putendl("IA win col");
				return (1);
			}
		}
		else
		{
			w = 0;
			i++;
		}
	}
	return (0);
}

int			ft_check(int maxline, int maxcol, int line, int col)
{
	if (ft_check_line(maxcol, line) == 1 || ft_check_col(maxline, col) == 1)
		return (1);
	else
		return (0);
}
