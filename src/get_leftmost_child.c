/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_leftmost_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:25:33 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:08:18 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *n, int level)
{
	if (!n)
		return (ft_error("NULL passed to get_leftmost_child()"));
	if (level < 0)
		return (ft_error("Invalid level passed to get_leftmost_child()"));
	return (0);
}

t_tree		*get_leftmost_child(t_tree *node, int level)
{
	if (!input_error(node, level))
	{
		while (level > 0)
		{
			if (!node)
				return (NULL);
			node = node->ptrs[0];
			level--;
		}
		if (node)
			return (node);
	}
	return (NULL);
}
