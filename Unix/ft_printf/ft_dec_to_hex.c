/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:48:37 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/21 18:24:50 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

static char		*ft_check_alpha(int size, unsigned int n);
static char		*ft_check_maj_alpha(int size, unsigned int n);
static char		*ft_memory(int n);

char			*ft_dec_to_hex(const char **format, unsigned int n)
{
	char	*str;
	char	*new;
	int		size;

	size = ft_nsize_hex(n);
	new = NULL;
	if (n == 0)
	{
		if ((new = ft_strnew(1)) == NULL)
			return (NULL);
		new[0] = '0';
		return (new);
	}
	else if (n > 0 && **format == 'x')
	{
		str = ft_check_alpha(size, n);
		return (str);
	}
	else if (n > 0 && **format == 'X')
	{
		str = ft_check_maj_alpha(size, n);
		return (str);
	}
	return (0);
}

static char		*ft_check_alpha(int size, unsigned int n)
{
	char	*str;

	str = ft_memory(size);
	while (size > 0)
	{
		str[size - 1] = (n % 16) + 48;
		if (str[size - 1] == 58)
			str[size - 1] = 'a';
		else if (str[size - 1] == 59)
			str[size - 1] = 'b';
		else if (str[size - 1] == 60)
			str[size - 1] = 'c';
		else if (str[size - 1] == 61)
			str[size - 1] = 'd';
		else if (str[size - 1] == 62)
			str[size - 1] = 'e';
		else if (str[size - 1] == 63)
			str[size - 1] = 'f';
		size--;
		n = n / 16;
	}
	return (str);
}

static char		*ft_memory(int n)
{
	char	*str;

	str = NULL;
	if ((str = ft_strnew(n)) == NULL)
		return (NULL);
	return (str);
}

static char		*ft_check_maj_alpha(int size, unsigned int n)
{
	char	*str;

	str = ft_memory(size);
	while (size > 0)
	{
		str[size - 1] = (n % 16) + 48;
		if (str[size - 1] == 58)
			str[size - 1] = 'A';
		else if (str[size - 1] == 59)
			str[size - 1] = 'B';
		else if (str[size - 1] == 60)
			str[size - 1] = 'C';
		else if (str[size - 1] == 61)
			str[size - 1] = 'D';
		else if (str[size - 1] == 62)
			str[size - 1] = 'E';
		else if (str[size - 1] == 63)
			str[size - 1] = 'F';
		size--;
		n = n / 16;
	}
	return (str);
}
