/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_ptr_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:04:59 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 16:35:47 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(void *n, int i, int p)
{
	if (!n)
		return (ft_error("NULL node pointer passed to ins_ptr_at()"));
	if (i < 0 || i >= NODE_CAPACITY)
		return (ft_error("Invalid index passed to ins_ptr_at()"));
	if (!p)
		ft_error("WARNING: NULL ptr passed to ins_ptr_at()");
	return (0);
}

void		ins_ptr_at(t_tree *node, int index, void *ptr)
{
	if (!input_error(node, index, ptr))
	{
		if (index > node->num_ptrs)
			ft_error("WARNING: Index is past current capacity in ins_ptr_at()");
		shift_ptrs_right(node, index);
		node->ptrs[index] = ptr;
	}
}
