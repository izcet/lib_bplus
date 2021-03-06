/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 00:06:44 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:44:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error_node(t_tree *node)
{
	if (!node)
		return (ft_error("NULL passed to split_right()"));
	return (0);
}

t_tree		*split_right(t_tree *left)
{
	t_tree	*right;

	if (input_error_node(left))
		return (NULL);
	right = new_node(left->is_leaf, left->parent);
	if (!right)
		return (NULL);
	while (left->num_ptrs > right->num_ptrs)
		pass_ptr_right(left, right);
	update_keys(right);
	return (right);
}

static int	input_error_root(t_tree **root)
{
	if (!root || !(*root))
		return (ft_error("NULL passed to split_root()"));
	if ((*root)->parent)
		return (ft_error("\"Root\" node has a parent in split_root()"));
	return (0);
}

t_tree		*split_root(t_tree **root)
{
	t_tree	*left;
	t_tree	*right;
	t_tree	*new;

	if (!input_error_root(root))
	{
		new = new_node(0, NULL);
		left = *root;
		left->parent = new;
		right = split_right(left);
		ins_ptr_at(new, 0, left);
		ins_ptr_at(new, 1, right);
		*root = new;
		printf("Calling update from splitroot\n");
		update_keys(left);
		update_keys(right);
	}
	return (*root);
}
