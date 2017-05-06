/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_ptr_in_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:42:42 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:44:16 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static t_tree	*capacity_leaf(t_tree **root, t_tree *node, void *ptr,
		int (*f)(void *, void *))
{
	t_tree *right;

	if (f(((t_leaf*)ptr)->key, ((t_leaf*)node->ptrs[NODE_CAPACITY - 1])->key) > 0)
		right = make_space(root, node, 1, f);
	else
		right = make_space(root, node, 0, f);
	if (right)
	{
		if (f(((t_leaf*)ptr)->key, ((t_leaf*)(right->ptrs[0]))->key) < 0)
			ins_ptr_in_node(*root, node, ptr, f);
		else
			ins_ptr_in_node(*root, right, ptr, f);
		return (right);
	}
	return (NULL);
}

static t_tree	*capacity_branch(t_tree **root, t_tree *node, void *ptr,
		int (*f)(void *, void*))
{
	t_tree	*right;

	if (f(get_lowest_key(ptr), get_lowest_key(node->ptrs[NODE_CAPACITY - 1])) > 0)
		right = make_space(root, node, 1, f);
	else
		right = make_space(root, node, 0, f);
	if (right)
	{
		if (f(get_lowest_key(ptr), get_lowest_key(right->ptrs[0])) < 0)
			ins_ptr_in_node(*root, node, ptr, f);
		else
			ins_ptr_in_node(*root, right, ptr, f);
		return (right);
	}
	return (NULL);
}

// returns newly created node
static t_tree	*capacity_add(t_tree **root, t_tree *node, void *ptr,
		int (*f)(void *, void *))
{
	if (node->is_leaf)
		return (capacity_leaf(root, node, ((t_leaf*)ptr)->key, f));
	else
		return (capacity_branch(root, node, get_lowest_key(ptr), f));
}

static void		sub_capacity_add(t_tree *node, void *ptr,
		int (*f)(void *, void *))
{
	int		i;

	i = 0;
	if (node->is_leaf)
	{
		while (i < node->num_ptrs && f(((t_leaf*)ptr)->key, ((t_leaf*)(node->ptrs[i]))->key) >= 0)
			i++;
	}
	else
	{
		while (i < node->num_ptrs && f(get_lowest_key(ptr), get_lowest_key(node->ptrs[i])) >= 0)
			i++;
	}
	ins_ptr_at(node, i, ptr);
}

// returns root
t_tree			*ins_ptr_in_node(t_tree *root, t_tree *node, void *ptr,
		int (*f)(void *, void *))
{
	if (!root || !node || !ptr || !f)
	{
		ft_error("NULL passed to ins_ptr_in_node()");
		return (root);
	}
	if (node->num_ptrs >= NODE_CAPACITY)
		if (capacity_add(&root, node, ptr, f))
			return (root);
	sub_capacity_add(node, ptr, f);
	update_keys(node);
	return (root);
}
