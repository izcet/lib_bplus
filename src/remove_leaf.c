/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_leaf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:06:30 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 20:25:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(void *r, void *k, void *f)
{
	if (!r || !k || !f)
		return (1);
	return (0);
}

// revise this to return a list rather than a single leaf
t_leaf		*remove_leaf(t_tree **root, void *key, int (*f)(void *, void *))
{
	t_tree	*node;
	t_leaf	*leaf;
	int		i;

	if (input_error(root, key, f))
		return (NULL);
	node = *root;
	while (node && !(node->is_leaf))
	{
		i = get_first_of_key(node, key, f);
		if (i < 0)
		{
			ft_error("Invalid next index in remove()");
			return (NULL);
		}
		node = node->ptrs[i];
	}
	leaf = rm_leaf(node, get_first_of_key(node, key, f));
	*root = condense(root, node);
	return (leaf);
}
