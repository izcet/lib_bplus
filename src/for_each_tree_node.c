/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_tree_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:13:26 by irhett            #+#    #+#             */
/*   Updated: 2017/05/06 13:29:00 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree **n, void *f)
{
	if (!n || !(*n) || !f)
		return (ft_error("NULL passed to for_each_tree_node()"));
	return (0);
}

void	for_each_tree_node(t_tree **node, void *(*function)(void *))
{
	int		i;

	if (!input_error(node, function))
	{
		i = 0;
		function(*node);
		if (!(*node)->is_leaf)
		{
			while (i < (*node)->num_ptrs)
			{
				printf("(%p) calling f on child %i(%p)\n", *node, i, (*node)->ptrs[i]);
				for_each_tree_node((t_tree **)&((*node)->ptrs[i++]), function);
			}
		}
	}
}
