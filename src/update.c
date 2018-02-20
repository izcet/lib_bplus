/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:23:27 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:11:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error_keys(t_tree *node)
{
	if (!node)
		ft_error("NULL passed to update_keys()");
	return (0);
}

void		update_keys(t_tree *node)
{
	int		i;
	if (!input_error_keys(node))
	{
		i = 1;
		while (i < node->num_ptrs)
		{
			if (node->is_leaf)
				node->keys[i - 1] = ((t_leaf *)(node->ptrs[i]))->key;
			else
				node->keys[i - 1] = get_lowest_key(node->ptrs[i]);
			i++;
		}
		while (i < NODE_CAPACITY - 1)
			node->keys[(++i) - 1] = NULL;
		if (node->parent)
			update_keys(node->parent);
	}
}

static int	input_error_leaf(t_tree **r, void *k, void *l, void *f)
{
	if (!r || !(*r) || !k || !l || !f)
		return (ft_error("NULL passed to update_leaf()"));
	return (0);
}

t_leaf		*update_leaf(t_tree **root, void *k, t_leaf *leaf,
		int (*f)(void *, void *))
{
	t_leaf	*ret;

	if (input_error_leaf(root, k, leaf, f))
		return (NULL);
	ret = remove_leaf(root, k, f);
	if (ret)
	{
		*root = add_leaf(*root, leaf, f);
		return (ret);
	}
	return (NULL);
}
