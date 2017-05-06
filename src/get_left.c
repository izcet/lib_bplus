/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 00:54:40 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:08:13 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *n)
{
	if (!n)
		return (ft_error("NULL passed to get_left()"));
	return (0);
}

t_tree		*get_left(t_tree *node)
{
	int		i;
	int		level;
	if (!input_error(node))
	{
		level = 0;
		while (node->parent)
		{
			i = get_index(node);
			if (i < 0)
				return (NULL);
			if (i > 0)
				return (get_rightmost_child(node->parent->ptrs[i - 1], level));
			level++;
			node = node->parent;
		}
	}
	return (NULL);
}
