/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:12:58 by nschilli          #+#    #+#             */
/*   Updated: 2014/03/26 23:36:22 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void		infix(char ***env, t_tree *tree, int i)
{
	t_fd *fd;

	fd = ft_init_fd();
	if (tree->left == NULL && tree->right == NULL && i == 0)
		do_the_cmd(env, ft_strsplit(tree->name, ' '), fd);
	if (tree->left != NULL)
	{
		if (tree->left->type != 5)
			infix(env, tree->left, i + 1);
		tree = ft_board_operator(env, tree);
	}
	if (tree->right != NULL && tree->right->type != 5)
		infix(env, tree->right, i + 1);
}

t_tree		*new_node(t_tree *tree, t_tree *father, char *name, int type)
{
	if (tree == NULL)
	{
		if (!(tree = (t_tree*)malloc(sizeof(t_tree))))
			ft_error(1, "new_node");
		tree->name = name;
		tree->type = type;
		tree->exec = -1;
		tree->father = father;
		tree->right = NULL;
		tree->left = NULL;
	}
	return (tree);
}

void		tree_right(t_tree **tree, char *name, int type)
{
	t_tree	*t_right;

	t_right = *tree;
	while (t_right->right != NULL)
		t_right = t_right->right;
	t_right->right = new_node(t_right->right, t_right, name, type);
}

void		tree_left(t_tree **tree, char *name, int type)
{
	t_tree	*t_left;

	t_left = *tree;
	while (t_left->left != NULL)
		t_left = t_left->left;
	t_left->left = new_node(t_left->left, t_left, name, type);
}

t_tree		*create_tree(t_token *list, t_tree *node)
{
	node = new_node(NULL, node, NULL, -1);
	if (find_operator(list))
	{
		node->name = find_priority(list)->name;
		node->type = find_priority(list)->type;
		node->left = create_tree(get_left_op(list), node);
		if (find_priority(list)->next != NULL)
			node->right = create_tree(find_priority(list)->next, node);
		return (node);
	}
	else
	{
		node->name = list->name;
		node->type = list->type;
		return (node);
	}
	return (NULL);
}
