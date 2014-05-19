/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 12:04:05 by lcharpen          #+#    #+#             */
/*   Updated: 2014/02/10 15:38:33 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_cpy_str(char *str);
static char	*ft_strsub2(char *s, int i, int len);
static int	ft_check_n(char *str);
static int	ft_error(char *s1, char *s2);

int			get_next_line(int const fd, char **line)
{
	char		buf[BUF_SIZE + 1];
	static char	*str = NULL;
	int			i;
	static int	ret = -1;

	*line = (str == NULL ? ft_strnew(BUF_SIZE) : ft_cpy_str(str));
	while ((i = ft_check_n(*line)) < 0 && ret != 0 && ret != -2)
	{
		if ((ret = read(fd, buf, BUF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		str = ft_strjoin(*line, buf);
		*line = ft_cpy_str(str);
	}
	str = ft_strsub2(*line, i + 1, ft_strlen(*line) - i);
	if (ret == 0)
	{
		if (*line[0] == '\0')
			return (0);
		ret = -2;
		return (1);
	}
	else if (ret == -2)
		return (0);
	return (ft_error(*line, str));
}

static char	*ft_cpy_str(char *str)
{
	char	*strtmp;
	int		i;

	i = ft_strlen(str);
	strtmp = ft_strnew(i);
	ft_strcpy(strtmp, str);
	return (strtmp);
}

static int	ft_check_n(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] == '\n')
			return (n);
		n++;
	}
	return (-1);
}

static char	*ft_strsub2(char *line, int start, int len)
{
	char	*new;
	int		i;

	new = NULL;
	i = 0;
	if ((new = (char *)malloc(sizeof(len + 1))) != NULL)
	{
		while (i < len)
		{
			new[i] = line[start + i];
			i++;
		}
	}
	line[start - 1] = '\0';
	return (new);
}

static int	ft_error(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	return (1);
}
