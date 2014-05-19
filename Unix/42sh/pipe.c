/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 14:08:56 by jgil              #+#    #+#             */
/*   Updated: 2014/03/27 19:33:14 by jgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

int				find_char(char *str, char x)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == x)
				return (i);
			i++;
		}
	}
	return (-1);
}

static void		recursive_pipe(char ***env, t_tree *tree, t_fd *fd)
{
	pid_t	father;
	int		tube[2];

	pipe(tube);
	father = fork();
	if (father)
	{
		close(tube[1]);
		dup2(tube[0], 0);
		wait(NULL);
	}
	else
	{
		close(tube[0]);
		dup2(tube[1], 1);
		if (tree->father && tree->father->type == 3)
			recursive_pipe(env, tree->father, fd);
		exit(2);
	}
	if (tree->left->type == 4)
		ft_operator_four(env, tree->left);
	else
		do_the_cmd(env, ft_strsplit(tree->left->name, ' '), fd);
}

void			exec_pipe(char ***env, t_tree *tree, t_fd *fd)
{
	pid_t	father;
	int		tube[2];

	while (tree->right && tree->right->type == 3)
		tree = tree->right;
	pipe(tube);
	father = fork();
	if (father)
	{
		close(tube[1]);
		dup2(tube[0], 0);
		wait(NULL);
	}
	else
	{
		close(tube[0]);
		dup2(tube[1], 1);
		recursive_pipe(env, tree, fd);
		exit(2);
	}
	if (tree->right->type == 4)
		ft_operator_four(env, tree->right);
	else
		do_the_cmd(env, ft_strsplit(tree->right->name, ' '), fd);
	exit(2);
}
