/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:53:23 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:07:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *p, t_tree *c)
{
	if (!p || !c)
		return (ft_error("NULL passed to get_index_of_child()"));
	return (0);
}

int			get_index_of_self(t_tree *node)
{
	if (!input_error(node, node))
	{
		if (node->parent)
			return (get_index_of_child(node->parent, node));
	}
	return (-1);
}

int			get_index_of_child(t_tree *parent, t_tree *child)
{
	int		i;
	if (!input_error(parent, child))
	{
		i = 0;
		while (i < parent->num_ptrs)
		{
			if (parent->ptrs[i] == child)
				return (i);
			i++;
		}
		ft_error("Child not found in get_index_of_child()");
	}
	return (-1);
}
