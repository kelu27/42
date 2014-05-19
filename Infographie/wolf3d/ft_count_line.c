/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 14:18:49 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/13 17:03:53 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_count_line(char *argv)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open failed\n");
		exit(0);
	}
	else
	{
		i = 0;
		while (get_next_line(fd, &line) > 0)
		{
			i++;
			free(line);
		}
		close(fd);
	}
	return (i);
}

int		*ft_convert(char *line)
{
	int		j;
	int		*tab;
	char	**split;

	j = 0;
	split = ft_strsplit(line, ' ');
	tab = (int *)malloc(sizeof(int) * ft_str_strlen(split) + 1);
	while (j <= ft_str_strlen(split))
	{
		tab[j] = ft_atoi(split[j]);
		j++;
	}
	return (tab);
}

int		ft_str_strlen(char	**str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	fill_in_tab(char *argv, t_env *e)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv, O_RDONLY);
	line = NULL;
	if (fd == -1)
	{
		ft_putstr("Open failed\n");
		exit(0);
	}
	else
	{
		i = 0;
		e->tab = (int **)malloc(sizeof(int *) * ft_count_line(argv));
		while (get_next_line(fd, &line) == 1)
		{
			if (ft_strlen(line))
			{
				e->tab[i] = ft_convert(line);
				i++;
			}
		}
	}
	e->numline = i;
}
