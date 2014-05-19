/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 22:32:04 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/16 22:46:40 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <ft_p.h>
#include <stdio.h>

void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

int		create_client(char *addr, int port)
{
	int						sock;
	struct protoent			*proto;
	struct sockaddr_in		sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Connect error\n");
		exit(-42);
	}
	return (sock);
}

void	ft_read_client(t_client *e)
{
	int		r2;

	e->buff[e->r - 1] = '\0';
	write(e->sock, e->buff, e->r);
	if (ft_strcmp("ls", e->buff) == 0 || ft_strcmp("pwd", e->buff) == 0
			|| ft_strncmp("cd ", e->buff, 3) == 0)
	{
		while ((r2 = read(e->sock, e->buff, 1)) > 0 && e->buff[0] != '\0')
		{
			e->buff[r2] = '\0';
			write(1, e->buff, r2);
		}
	}
	else if (ft_strncmp("get ", e->buff, 4) == 0)
		ft_get_client(e);
	else if (ft_strncmp("put ", e->buff, 4) == 0)
		ft_put_client(e);
	else if (ft_strcmp("quit", e->buff) == 0)
	{
		ft_putendl("SUCCESS");
		exit(0);
	}
	ft_putstr(">> ");
}

int		main(int argc, char *argv[])
{
	int			port;
	t_client	e;

	if (argc != 3)
		usage(argv[0]);
	port = ft_atoi(argv[2]);
	e.sock = create_client(argv[1], port);
	ft_putstr(">> ");
	while ((e.r = read(0, e.buff, 1023)) > 0)
		ft_read_client(&e);
	close(e.sock);
	return (0);
}
