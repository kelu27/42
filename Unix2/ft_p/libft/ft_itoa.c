/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:48:37 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/21 18:59:57 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static char		*ft_memory(int n)
{
	char	*str;

	str = NULL;
	if ((str = ft_strnew(n)) == NULL)
		return (NULL);
	return (str);
}

static char		*ft_negativ(int size, long int n)
{
	char	*str;

	str = ft_memory(size);
	n = -n;
	while (size > 0)
	{
		str[size - 1] = (n % 10) + '0';
		size--;
		n = n / 10;
	}
	str[0] = '-';
	return (str);
}

static char		*ft_positiv(int size, long int n)
{
	char	*str;

	str = ft_memory(size);
	while (size > 0)
	{
		str[size - 1] = (n % 10) + '0';
		size--;
		n = n / 10;
	}
	return (str);
}

static int		ft_nsize(int n)
{
	int		size;

	size = 1;
	if (n > 0)
	{
		while ((n / 10) != 0)
		{
			n = n / 10;
			size++;
		}
	}
	else
	{
		while ((n / 10) != 0)
		{
			n = n / 10;
			size++;
		}
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	char	*new;
	int		size;

	size = ft_nsize(n);
	new = NULL;
	if (n == 0)
	{
		if ((new = ft_strnew(1)) == NULL)
			return (NULL);
		new[0] = '0';
		return (new);
	}
	if (n > 0)
		str = ft_positiv(size, n);
	if (n < 0)
		str = ft_negativ(size, n);
	return (str);
}
