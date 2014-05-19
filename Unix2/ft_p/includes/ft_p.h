/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 22:41:37 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/16 22:41:40 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include "../libft/includes/libft.h"
# include <arpa/inet.h>

typedef struct			s_serv
{
	int					cs;
	int					port;
	pid_t				pid;
	struct sockaddr_in	csin;
	unsigned int		cslen;
	char				home[1024];
	int					sock;
	char				buff[1024];
	char				tmp[1];
	int					r;
	int					counter;
	int					i;
	char				*pwd;
	int					ret;
	int					fd;
	int					r2;
	char				**tab;
}						t_serv;

typedef struct			s_client
{
	int					sock;
	char				buff[1024];
	char				tmp[1];
	int					i;
	int					r;
	int					r2;
	int					fd;
	int					ret;
	char				**tab;
}						t_client;

void					ft_ls(int cs);
void					ft_pwd(int cs, char *home);
void					ft_cd(t_serv *e);
void					ft_get_serv(t_serv *e);
void					ft_put_serv(t_serv *e);
void					ft_get_client(t_client *e);
void					ft_put_client(t_client *e);
#endif
