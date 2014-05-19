/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsize_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:00:28 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/21 17:49:38 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nsize_oct(unsigned int n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (size);
	else if (n > 0)
	{
		while ((n / 8) != 0)
		{
			n = n / 8;
			size++;
		}
	}
	else
	{
		while ((n / 8) != 0)
		{
			n = n / 8;
			size++;
		}
		size++;
	}
	return (size);
}
