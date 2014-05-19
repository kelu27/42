/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 23:39:54 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/17 00:06:40 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>
#include <unistd.h>
#include <dirent.h>

void	ft_ls(int cs)
{
	DIR				*dir;
	struct dirent	*p;
	char			*fic;

	if (!(dir = opendir(".")))
		ft_putendl_fd("ERROR: ls failed", cs);
	else
		ft_putendl_fd("SUCCESS", cs);
	while ((p = readdir(dir)))
	{
		fic = p->d_name;
		if (ft_strncmp(".", fic, 1) != 0)
			ft_putendl_fd(fic, cs);
	}
	write(cs, "\0", 1);
	closedir(dir);
}

void	ft_pwd(int cs, char *home)
{
	char	pwd[1024];

	getcwd(pwd, 1024);
	ft_putendl_fd("SUCCESS", cs);
	if (*(pwd + ft_strlen(home)) != '/')
		ft_putstr_fd("/", cs);
	ft_putendl_fd(pwd + ft_strlen(home), cs);
	write(cs, "\0", 1);
}

void	ft_cd2(char *path, int k, t_serv *e)
{
	char	newpwd[1024];

	if (chdir(path) == -1)
	{
		ft_putendl_fd("ERROR: Repository doesn't exist", e->cs);
		k = 0;
	}
	getcwd(newpwd, 1024);
	if (ft_strcmp(e->pwd, newpwd) > 0)
	{
		chdir(e->pwd);
		k = 0;
		ft_putstr_fd("ERROR: You don't have permission to access", e->cs);
		ft_putendl_fd("to the parent directory", e->cs);
	}
	if (k == 1)
		ft_putendl_fd("SUCCESS", e->cs);
	write(e->cs, "\0", 1);
}

void	ft_cd(t_serv *e)
{
	char	*path;
	int		i;
	int		j;
	int		k;

	i = 3;
	j = 0;
	k = 1;
	path = ft_strdup(e->buff);
	while (e->buff[i])
	{
		path[j] = e->buff[i];
		j++;
		i++;
	}
	path[j] = '\0';
	ft_cd2(path, k, e);
}
