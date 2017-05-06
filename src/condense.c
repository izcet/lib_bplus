/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condense.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:29 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 19:46:39 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int		input_error(t_tree **r, void *n)
{
	if (!r || !(*r) || !n)
		return (ft_error("NULL passed to condense()"));
	return (0);
}

static t_tree	*condense_child(t_tree **root, t_tree *node)
{
	t_tree *other;

	if (can_pull_from_right(node))
		pass_ptr_left(node, (other = get_right(node)));
	else if (can_pull_from_left(node))
		pass_ptr_right((other = get_left(node)), node);
	else if (get_right(node))
	{
		other = (get_right(node))->parent;
		merge_left(node, get_right(node));
		condense(root, other);
	}
	else if (get_left(node))
	{
		other = (get_left(node))->parent;
		merge_right(get_left(node), node);
		condense(root, other);
	}
	else
		ft_error("Node with no neighbors has a parent?");
	update_keys(other);
	update_keys(node);
	return (condense(root, node->parent));
}

t_tree			*condense(t_tree **root, t_tree *node)
{
	if (input_error(root, node))
		return (*root);
	if (node->num_ptrs >= (NODE_CAPACITY / 2))
		return (*root);
	if (node->parent)
		*root = condense_child(root, node);
	else
	{
		if (node->is_leaf)
			return (node);
		else if (node->num_ptrs == 1)
		{
			*root = node->ptrs[0];
			del_node(node);
		}
	}
	return (*root);
}
