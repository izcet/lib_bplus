/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 00:06:44 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 19:38:16 by irhett           ###   ########.fr       */
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
	int		i;

	right = new_node(left->is_leaf, left->parent);
	if (!right)
		return (NULL);
	i = 0;
	while (i++ < (left->num_ptrs / 2))
		pass_ptr_right(left, right);
	update_keys(right);
	return (right);
}