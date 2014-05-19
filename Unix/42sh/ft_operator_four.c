/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 15:26:23 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/27 21:13:21 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "shell.h"

static void		ft_open_fildes_all(t_tree *tree, t_fd *f)
{
	if (ft_strcmp(tree->father->name, ">") == 0)
		f->fdout = open(tree->left->name, O_WRONLY | O_CREAT
				| O_TRUNC, 0666);
	else if (ft_strcmp(tree->father->name, ">>") == 0)
		f->fdout = open(tree->left->name, O_WRONLY | O_CREAT
				| O_APPEND, 0666);
	else if (ft_strcmp(tree->father->name, "<") == 0)
		f->fdin = open(tree->left->name, O_RDONLY);
}

static void		ft_open_fildes_one(char ***e, t_tree *tree, t_fd *f, char *str)
{
	if (ft_strcmp(tree->name, ">") == 0)
		f->fdout = open(tree->right->name, O_WRONLY | O_CREAT
				| O_TRUNC, 0666);
	else if (ft_strcmp(tree->name, ">>") == 0)
		f->fdout = open(tree->right->name, O_WRONLY | O_CREAT
				| O_APPEND, 0666);
	else if (ft_strcmp(tree->name, "<") == 0)
		f->fdin = open(tree->right->name, O_RDONLY);
	if (f->fdin < 0)
		ft_putendl_fd("no such file or directory", 2);
	else
		tree->exec = do_the_cmd(e, ft_strsplit(str, ' '), f);
}

static t_tree	*ft_operator_four_2(char ***e, t_tree *tree, t_fd *f)
{
	int		i;
	char	*str;
	t_tree	*temp;

	temp = tree;
	i = -1;
	str = ft_strdup(tree->left->name);
	while (++i, temp->type == 4)
		temp = temp->right;
	if (i > 1)
		tree = tree->right;
	while (i > 1)
	{
		ft_open_fildes_all(tree, f);
		if (f->fdin < 0)
			ft_putendl_fd("no such file or directory", 2);
		else
			tree->exec = do_the_cmd(e, ft_strsplit(str, ' '), f);
		i--;
		if (tree->right->type == 4)
			tree = tree->right;
	}
	if (i == 1)
		ft_open_fildes_one(e, tree, f, str);
	return (tree);
}

t_tree			*ft_operator_four(char ***e, t_tree *tree)
{
	t_fd	*f;

	f = ft_init_fd();
	if (tree->right && tree->left && tree->name)
		tree = ft_operator_four_2(e, tree, f);
	else
		ft_putendl("");
	return (tree);
}
