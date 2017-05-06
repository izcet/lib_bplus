/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:08:21 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 18:54:30 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(void *r, void *n, int f)
{
	if (!r || !n)
		return (ft_error("NULL passed to make_space()"));
	return (0);
}

// returns if a split was necessary
t_tree		*make_space(t_tree **root, t_tree *node, void *ptr, int force)
{
	t_tree	*right;

	if (input_error(root, node))
		return (NULL);
	if (!node->parent)
	{
		*root = split_root(root);
		return (root->ptrs[1]);
	}
	if (!force)
	{
		if (get_right(node) && !is_full(get_right(node)))
		{
			pass_ptr_right(node, get_right(node));
			return (NULL);
		}
		if (get_left(node) && !is_full(get_left(node)))
		{
			pass_ptr_left(get_left(node), node);
			return (NULL);
		}
	}
	return (split_right(node));
}
