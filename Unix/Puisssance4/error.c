/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballu <vballu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:11:45 by vballu            #+#    #+#             */
/*   Updated: 2014/03/07 21:06:49 by vballu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "alcu.h"

t_bool		ft_badarg(void)
{
	static t_bool error = false;

	if (!error)
	{
		ft_putendl_fd("error arguments", 2);
		error = true;
	}
	return (error);
}
