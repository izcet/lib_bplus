/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_leaf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:34:29 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:11:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(void *n, int i)
{
	if (!n)
		return (ft_error("NULL passed to rm_leaf()"));
	if (!(((t_tree *)n)->is_leaf))
		return (ft_error("Tried to take a leaf from a branch in rm_leaf()"));
	if (i < 0 || i >= ((t_tree *)n)->num_ptrs || i >= NODE_CAPACITY)
		return (ft_error("Invalid index passed to rm_leaf()"));
	return (0);	
}

t_leaf		*rm_leaf(t_tree *node, int index)
{
	if (input_error(node, index))
		return (NULL);
	return (del_ptr_at(node, index));
}
