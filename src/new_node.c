/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:57:43 by irhett            #+#    #+#             */
/*   Updated: 2017/05/04 22:40:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	init_node(t_tree *node)
{
	node->ptrs = (void**)malloc(sizeof(void *) * NODE_CAPACITY);
	if (!(node->ptrs))
		return (1);
	node->keys = (void**)malloc(sizeof(void *) * (NODE_CAPACITY - 1));
	if (!(node->keys))
	{
		free(node->ptrs);
		return (1);
	}
	return (0);
}

t_tree		*new_node(int is_leaf, t_tree *parent)
{
	t_tree	*node;

	node = (t_tree*)malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_tree));
	if (is_leaf)
		node->is_leaf = 1;
	node->parent = parent;
	if (init_node(node))
	{
		free(node);
		node = NULL;
	}
	return (node);
}
