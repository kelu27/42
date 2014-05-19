/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 15:10:54 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/18 21:02:46 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

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

void	ft_get_client(t_client *e)
{
	char	size[8];
	int		fd;

	e->i = 0;
	e->tab = ft_strsplit(e->buff, ' ');
	ft_bzero(size, 8);
	while ((e->r = read(e->sock, e->tmp, 1) > 0) && e->tmp[0] != '\0')
		size[e->i++] = e->tmp[0];
	if (!ft_strncmp("ERROR", size, 5))
	{
		ft_putendl("ERROR: FILE NOT FOUND");
		return ;
	}
	if ((fd = open(name(e->tab[1]), O_CREAT | O_WRONLY | O_APPEND, 0666)) != -1)
	{
		while ((e->r2 = read(e->sock, e->buff, ft_atoi(size))) > 0)
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

void	ft_put_client(t_client *e)
{
	char		**file;
	int			size;
	struct stat buf[1024];
	int			fd;

	file = ft_strsplit(e->buff, ' ');
	if ((fd = open(file[1], O_RDONLY)) > 0)
	{
		if ((e->ret = fstat(fd, buf)) == -1)
			ft_putendl("ERROR: fstat failed");
		size = (int)buf->st_size;
		write(e->sock, ft_itoa(size), ft_strlen(ft_itoa(size)));
		write(e->sock, "\0", 1);
		while ((e->r2 = read(fd, e->buff, (size_t)size)) > 0)
		{
			e->buff[e->r2] = '\0';
			write(e->sock, e->buff, e->r2);
		}
	}
	else
	{
		write(e->sock, "ERROR", 5);
		write(e->sock, "\0", 1);
	}
}
