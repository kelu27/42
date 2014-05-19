/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 10:25:46 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/18 21:05:53 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*name(char *path)
{
	char	*ssc;
	int		l;

	l = 0;
	ssc = ft_strstr(path, "/");
	while (ssc)
	{
		l = ft_strlen(ssc) + 1;
		path = &path[ft_strlen(path) - l + 2];
		ssc = ft_strstr(path, "/");
	}
	return (path);
}

void	ft_get_serv(t_serv *e)
{
	char		**file;
	int			size;
	struct stat buf[1024];
	int			fd;

	file = ft_strsplit(e->buff, ' ');
	if ((fd = open(file[1], O_RDONLY)) < 0)
	{
		write(e->cs, "ERROR", 5);
		write(e->cs, "\0", 1);
		return ;
	}
	if ((e->ret = fstat(fd, buf)) == -1)
		ft_putendl_fd("ERROR: fstat failed", e->cs);
	size = (int)buf->st_size;
	write(e->cs, ft_itoa(size), ft_strlen(ft_itoa(size)));
	write(e->cs, "\0", 1);
	while ((e->r2 = read(fd, e->buff, (size_t)size)) > 0)
	{
		e->buff[e->r2] = '\0';
		write(e->cs, e->buff, e->r2);
	}
}

void	ft_put_serv(t_serv *e)
{
	char	size[8];
	int		fd;

	e->i = 0;
	e->tab = ft_strsplit(e->buff, ' ');
	ft_bzero(size, 8);
	while ((e->r = read(e->cs, e->tmp, 1) > 0) && e->tmp[0] != '\0')
		size[e->i++] = e->tmp[0];
	if (!ft_strncmp("ERROR", size, 5))
	{
		ft_putendl("ERROR: FILE NOT FOUND");
		return ;
	}
	if ((fd = open(name(e->tab[1]), O_CREAT | O_WRONLY | O_APPEND, 0666)) != -1)
	{
		while ((e->r2 = read(e->cs, e->buff, ft_atoi(size))) > 0)
		{
			e->buff[e->r2] = '\0';
			write(fd, e->buff, ft_atoi(size));
			break ;
		}
		ft_putendl("SUCCESS");
	}
	else
		ft_putendl("ERROR");
}
