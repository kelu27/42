/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 11:16:57 by jgil              #+#    #+#             */
/*   Updated: 2014/03/26 18:10:12 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_and_operator(char ***env, t_tree *tree, t_fd *fd)
{
	if (tree->left->exec == 0)
		tree->exec = 0;
	else if (tree->left->exec == 1)
		tree->exec = 1;
	if (tree->father && !ft_strcmp(tree->father->name, "&&")
		&& tree->father->exec == 0)
		tree->exec = 0;
	else if (tree->father && !ft_strcmp(tree->father->name, "||")
		&& tree->father->exec == 1)
		tree->exec = 1;
	if (tree->exec == -1 && tree->left->type == 5)
		tree->exec = do_the_cmd(env, ft_strsplit(tree->left->name, ' '), fd);
	if (tree->exec == 1 && tree->right->type == 5)
		do_the_cmd(env, ft_strsplit(tree->right->name, ' '), fd);
}

static void		ft_or_operator(char ***env, t_tree *tree, t_fd *fd)
{
	if (tree->left->exec == 0)
		tree->exec = 0;
	else if (tree->left->exec == 1)
		tree->exec = 1;
	if (tree->father && !ft_strcmp(tree->father->name, "||")
		&& tree->father->exec == 1)
		tree->exec = 1;
	else if (tree->father && !ft_strcmp(tree->father->name, "&&")
		&& tree->father->exec == 0)
		tree->exec = 0;
	if (tree->exec == -1 && tree->left->type == 5)
		tree->exec = do_the_cmd(env, ft_strsplit(tree->left->name, ' '), fd);
	if (tree->exec == 0 && tree->right->type == 5)
		do_the_cmd(env, ft_strsplit(tree->right->name, ' '), fd);
}

void			ft_operator_two(char ***env, t_tree *tree)
{
	t_fd	*fd;

	fd = ft_init_fd();
	if (tree->right && tree->left && tree->name)
	{
		if (!ft_strcmp(tree->name, "&&"))
			ft_and_operator(env, tree, fd);
		else
			ft_or_operator(env, tree, fd);
	}
	else
		ft_putendl("");
}
