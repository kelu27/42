/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 15:56:34 by jgil              #+#    #+#             */
/*   Updated: 2014/04/14 15:10:06 by jgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#define BUFF_SIZE 256

static int		ft_check_error(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	return (1);
}

static int		ft_find_n(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char		*ft_save_buf(char *s, int start, int len)
{
	char	*str;
	int		i;

	str = ft_strnew(len);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	s[start - 1] = '\0';
	return (str);
}

static char		*ft_temp_to_line(char *src)
{
	char	*dest;
	int		i;

	i = ft_strlen(src);
	dest = ft_strnew(i);
	ft_strcpy(dest, src);
	free(src);
	return (dest);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*temp = NULL;
	int				n;
	static int		ret = -1;

	*line = (temp == NULL ? ft_strnew(BUFF_SIZE) : ft_temp_to_line(temp));
	while ((n = ft_find_n(*line)) < 0 && ret != 0 && ret != -2)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	temp = ft_save_buf(*line, n + 1, ft_strlen(*line) - n);
	if (ret == 0 || ret == -2)
	{
		ret = ret - 2;
		if (ret == -2)
			return (1);
		temp = NULL;
		return (0);
	}
	return (ft_check_error(*line, temp));
}
