/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:23:27 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 20:12:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *node)
{
	if (!node)
		ft_error("NULL passed to update_keys()");
	return (0);
}

void		update_keys(t_tree *node)
{
	int		i;

	if (!input_error(node))
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
			node->keys[(i++) - 1] = NULL;
		if (node->parent)
			update_keys(node->parent);
	}
}
