/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 13:59:55 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/22 20:22:24 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list args;
	va_list argss;
	int		ret;

	va_start(args, format);
	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_isdigit(*format) == 1)
				ret = ret + ft_check_num(&format, args, argss, ret);
			if ((ret = ft_check_arg(&format, args, ret)) == -1)
				return (0);
		}
		else if (*format != '%')
			ret = ft_putchar_ret(*format, ret);
		format++;
	}
	va_end(args);
	va_end(argss);
	return (ret);
}
