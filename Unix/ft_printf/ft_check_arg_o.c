/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:08:33 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/22 20:21:49 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_check_arg_o(const char **format, va_list args, int ret)
{
	if (**format == ' ')
	{
		(*format)++;
		if (**format == 'd')
		{
			ft_putchar(' ');
			ret = 1 + ft_argd(*format, args, ret);
		}
	}
	else if (**format != '\0')
	{
		ft_putchar(**format);
		ret++;
	}
	else
		ret = -1;
	return (ret);
}

int		ft_putchar_ret(char c, int ret)
{
	write (1, &c, 1);
	ret++;
	return (ret);
}
