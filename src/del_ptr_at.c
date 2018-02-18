/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ptr_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:13:58 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:11:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *n, int i)
{
	if (!n)
		return (ft_error("NULL pointer passed to del_ptr_at()"));
	if (i < 0 || i >= n->num_ptrs || i >= NODE_CAPACITY)
		return (ft_error("Invalid index passed to del_ptr_at()"));
	return (0);
}

void		*del_ptr_at(t_tree *node, int index)
{
	void	*ptr;
	ptr = NULL;
	if (!input_error(node, index))
	{
		ptr = node->ptrs[index];
		shift_ptrs_left(node, index);
	}
	return (ptr);
}
