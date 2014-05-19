/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsize_ld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:00:28 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/21 17:48:56 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nsize_ld(long int n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (size);
	else if (n > 0)
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
