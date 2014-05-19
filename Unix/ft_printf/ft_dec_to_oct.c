/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:48:37 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/19 20:03:45 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

static char		*ft_positiv(int size, unsigned int n);
static char		*ft_memory(unsigned int n);

char			*ft_dec_to_oct(unsigned int n)
{
	char	*str;
	char	*new;
	unsigned int		size;

	size = ft_nsize_oct(n);
	new = NULL;
	if (n == 0)
	{
		if ((new = ft_strnew(1)) == NULL)
			return (NULL);
		new[0] = '0';
		return (new);
	}
	else
		str = ft_positiv(size, n);
	return (str);
}

static char		*ft_positiv(int size, unsigned int n)
{
	char	*str;

	str = ft_memory(size);
	while (size > 0)
	{
		str[size - 1] = (n % 8) + '0';
		size--;
		n = n / 8;
	}
	return (str);
}

static char		*ft_memory(unsigned int n)
{
	char	*str;

	str = NULL;
	if ((str = ft_strnew(n)) == NULL)
		return (NULL);
	return (str);
}
