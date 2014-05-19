/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:22:15 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/26 12:59:31 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_push_swap.h"

static char		ft_nospace(char c);

int				ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		n;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	while (ft_nospace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = 44 - str[i++];
	while (ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10;
		n = str[i] - '0';
		nbr = nbr + n;
		i++;
	}
	return (nbr * sign);
}

static char		ft_nospace(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' || c == '\r'
			|| c == '\f' || c == ' ')
		return (1);
	return (0);
}
