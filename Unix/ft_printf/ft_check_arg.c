/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:18:50 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/22 19:53:16 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_arg(const char **format, va_list args, int ret)
{
	if (**format == 'd' || **format == 'i' || **format == 'u'
			|| **format == 'o')
		ret = ft_argd(*format, args, ret);
	else if (**format == 'c' || **format == 'p')
		ret = ft_argc(*format, args, ret);
	else if (**format == 's' || **format == 'x' || **format == 'X')
		ret = ft_args(*format, args, ret);
	else if (**format == 'l')
	{
		(*format)++;
		if (**format == 'd' || **format == 'u' || **format == 'o')
			ret = ft_argld(*format, args, ret);
	}
	else if (**format == '#')
		ret = ft_check_diez(format, args, ret);
	else
		ret = ft_check_arg_o(format, args, ret);
	return (ret);
}

int		ft_argd(const char *format, va_list args, int ret)
{
	int				d;
	unsigned int	u;

	if (*format == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_putnbr_ui(u);
		ret = ret + ft_nsize_ui(u);
	}
	else if (*format == 'o')
	{
		d = va_arg(args, int);
		ft_putstr(ft_dec_to_oct(d));
		ret = ret + ft_strlen(ft_dec_to_oct(d));
	}
	else
	{
		d = va_arg(args, int);
		ft_putnbr(d);
		ret = ret + ft_nsize(d);
	}
	return (ret);
}

int		ft_argc(const char *format, va_list args, int ret)
{
	char			c;
	unsigned long	i;
	void			*ptr;

	if (*format == 'p')
	{
		ptr = va_arg(args, void *);
		i = (char *)ptr - (char *)0;
		ft_putstr("0x");
		ft_putstr(ft_dec_to_hex_ul(&format, i));
		ret = ret + 2 + ft_strlen(ft_dec_to_hex_ul(&format, i));
	}
	else
	{
		c = va_arg(args, int);
		ret++;
		ft_putchar(c);
	}
	return (ret);
}

int		ft_args(const char *format, va_list args, int ret)
{
	char	*str;
	int		i;

	if (*format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			ft_putstr("(null)");
			ret = ret + 6;
		}
		else
		{
			ret = ret + ft_strlen(str);
			ft_putstr(str);
		}
	}
	else if (*format == 'x' || *format == 'X')
	{
		i = (va_arg(args, int));
		ft_putstr(ft_dec_to_hex(&format, i));
		ret = ret + ft_strlen(ft_dec_to_hex(&format, i));
		return (ret);
	}
	return (ret);
}

int		ft_argld(const char *format, va_list args, int ret)
{
	long int			ld;
	unsigned long int	ul;

	if (*format == 'u')
	{
		ul = va_arg(args, unsigned long int);
		ft_putnbr_ul(ul);
		ret = ret + ft_nsize_ul(ul);
	}
	else if (*format == 'o')
	{
		ul = va_arg(args, unsigned long int);
		ft_putstr(ft_dec_to_oct_ul(ul));
		ret = ret + ft_strlen(ft_dec_to_oct_ul(ul));
	}
	else
	{
		ld = va_arg(args, long int);
		ft_putnbr_ld(ld);
		ret = ret + ft_nsize_ld(ld);
	}
	return (ret);
}
