/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_leaf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:47:11 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 19:42:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_errors(void *r, void *l, void *c)
{
	if (!r || !l || !c)
		return (ft_error("NULL pointer passed to add_leaf()"));
	return (0);
}

t_tree		*add_leaf(t_tree *root, t_leaf *l, int (*compare)(void *, void *))
{
	t_tree		*node;
	int			i;

	if (input_errors(root, l, compare))
		return (root);
	node = root;
	while (node && !(node->is_leaf))
	{
		i = get_first_of_key(node, l->key, compare);
		if (i < 0)
		{
			ft_error("Invalid next index in add_leaf()");
			return (root);
		}
		node = node->ptrs[i];
	}
	root = ins_ptr_in_node(root, node, l, compare);
	return (root);
}
