/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rightmost_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:25:33 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 19:54:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *n, int level)
{
	if (!n)
		return (ft_error("NULL passed to get_rightmost_child()"));
	if (level < 0)
		return (ft_error("Invalid level passed to get_rightmost_child()"));
	return (0);
}

t_tree		*get_rightmost_child(t_tree *node, int level)
{
	if (!input_error(node, level))
	{
		while (level > 0)
		{
			if (!node)
				return (NULL);
			node = node->ptrs[node->num_ptrs - 1];
			level--;
		}
		if (node)
			return (node);
	}
	return (NULL);
}
