/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsize_ul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:00:28 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/22 18:15:21 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nsize_ul(unsigned long int n)
{
	int		size;

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
