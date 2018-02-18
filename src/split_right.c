/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 00:06:44 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:44:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *node)
{
	if (!node)
		return (ft_error("NULL passed to split_right()"));
	return (0);
}

t_tree		*split_right(t_tree *left)
{
	t_tree	*right;

	if (input_error(left))
		return (NULL);
	right = new_node(left->is_leaf, left->parent);
	if (!right)
		return (NULL);
	while (left->num_ptrs > right->num_ptrs)
		pass_ptr_right(left, right);
	update_keys(right);
	return (right);
}
