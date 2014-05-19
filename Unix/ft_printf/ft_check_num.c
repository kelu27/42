/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 20:35:00 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/22 18:14:12 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_num(const char **format, va_list args, va_list argss, int ret)
{
	int	n;
	int	l;
	int	i;

	i = 0;
	n = ft_atoi(*format);
	va_copy(argss, args);
	l = ft_nsize(va_arg(argss, int));
	while (ft_isdigit(**format) == 1)
		(*format)++;
	while (i < n - l)
	{
		ft_putchar(' ');
		i++;
	}
	ret = i;
	return (ret);
}
