/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 16:10:36 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/09 11:17:26 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int	ft_putoken(char *maxline, char *maxcol, char *numcol)
{
	int	i;
	int	j;
	int	l;
	int	m;
	int n;

	l = ft_atoi(maxline);
	m = ft_atoi(numcol);
	n = ft_atoi(maxcol);
	i = l - 1;
	j = m - 1;
	while (0 <= i)
	{
		if (map_singleton()->stage[i][j] == '.')
		{
			map_singleton()->stage[i][j] = 'X';
			break ;
		}
		i--;
	}
	ft_print_map();
	if (ft_check(l, n, i, j) == 1)
		return (1);
	return (0);
}

int	ft_putoken2(char *maxline, char *maxcol, char *numcol)
{
	int	i;
	int	j;
	int	l;
	int	m;
	int n;

	l = ft_atoi(maxline);
	m = ft_atoi(numcol);
	n = ft_atoi(maxcol);
	i = l - 1;
	j = m - 1;
	while (0 <= i)
	{
		if (map_singleton()->stage[i][j] == '.')
		{
			map_singleton()->stage[i][j] = '0';
			break ;
		}
		i--;
	}
	ft_print_map();
	if (ft_check(l, n, i, j) == 1)
		return (1);
	return (0);
}
