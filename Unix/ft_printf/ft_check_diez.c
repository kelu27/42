/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_diez.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:30:41 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/22 19:51:56 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_diez(const char **format, va_list args, int ret)
{
	(*format)++;
	if (**format == 'x')
	{
		ft_putstr("0x");
		ret = 2 + ft_args(*format, args, ret);
	}
	else if (**format == 'd' || **format == 'i')
		ret = ft_argd(*format, args, ret);
	return (ret);
}
