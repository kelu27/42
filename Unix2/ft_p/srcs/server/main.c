/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 22:35:10 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/17 00:15:01 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ft_p.h>
#include <stdio.h>

void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Bind error\n");
		exit(-42);
	}
	listen(sock, 42);
	return (sock);
}

void	ft_read_server(t_serv *e)
{
	while ((e->r = read(e->cs, e->buff, 1023)) > 0)
	{
		e->buff[e->r - 1] = '\0';
		printf("received %d bytes: [%s] from client N%d\n", e->r, e->buff,
			e->counter);
		if (ft_strcmp("ls", e->buff) == 0)
			ft_ls(e->cs);
		else if (ft_strcmp("pwd", e->buff) == 0)
			ft_pwd(e->cs, e->pwd);
		else if (ft_strncmp("cd ", e->buff, 3) == 0)
			ft_cd(e);
		else if (ft_strncmp("get ", e->buff, 4) == 0)
			ft_get_serv(e);
		else if (ft_strncmp("put ", e->buff, 4) == 0)
			ft_put_serv(e);
	}
}

void	ft_init(t_serv *e, char *av)
{
	e->counter = 0;
	e->port = ft_atoi(av);
	e->sock = create_server(e->port);
	getcwd(e->home, 1024);
	e->pwd = ft_strdup(e->home);
}

int		main(int argc, char *argv[])
{
	t_serv				e;

	if (argc != 2)
		usage(argv[0]);
	ft_init(&e, argv[1]);
	while (42)
	{
		e.cs = accept(e.sock, (struct sockaddr *)&e.csin, &e.cslen);
		if ((e.pid = fork()) == -1)
		{
			close(e.cs);
			continue ;
		}
		else if (e.pid > 0)
		{
			close(e.cs);
			e.counter++;
			continue ;
		}
		else if (e.pid == 0)
			e.counter++;
		ft_read_server(&e);
	}
	return (0);
}
