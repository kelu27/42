/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 15:23:35 by nschilli          #+#    #+#             */
/*   Updated: 2014/03/27 20:04:45 by jgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "shell.h"

static void		ft_operator_one(char ***env, t_tree *tree)
{
	t_fd	*fd;

	fd = ft_init_fd();
	if (tree->left && tree->left->type == 5)
		do_the_cmd(env, ft_strsplit(tree->left->name, ' '), fd);
	if (tree->right && tree->right->type == 5)
		do_the_cmd(env, ft_strsplit(tree->right->name, ' '), fd);
}

static void		ft_operator_three(char ***env, t_tree *tree)
{
	t_fd	*fd;

	fd = ft_init_fd();
	if (tree->left && tree->right)
		exec_pipe(env, tree, fd);
	else
		ft_putendl("");
}

t_tree			*ft_board_operator(char ***env, t_tree *tree)
{
	t_fd	*fd;
	pid_t	father;

	fd = ft_init_fd();
	if (tree->type == 1)
		ft_operator_one(env, tree);
	else if (tree->type == 2)
		ft_operator_two(env, tree);
	else if (tree->type == 3)
	{
		father = fork();
		if (father)
			wait(NULL);
		else
			ft_operator_three(env, tree);
		while (tree->right
				&& (tree->right->type == 3 || tree->right->type == 4))
			tree = tree->right;
	}
	else if (tree->type == 4 && (!tree->father || tree->father->type != 3))
		tree = ft_operator_four(env, tree);
	else if (tree->type == 5)
		do_the_cmd(env, ft_strsplit(tree->name, ' '), fd);
	return (tree);
}
