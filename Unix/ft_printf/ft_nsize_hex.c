/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsize_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:00:28 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/21 17:48:37 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nsize_hex(unsigned int n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (size);
	else if (n > 0)
	{
		while ((n / 16) != 0)
		{
			n = n / 16;
			size++;
		}
	}
	else
	{
		while ((n / 16) != 0)
		{
			n = n / 16;
			size++;
		}
		size++;
	}
	return (size);
}
