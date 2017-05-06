/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 23:51:44 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:10:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *l, t_tree *r)
{
	if (!l || !r)
		return (ft_error("NULL passed to merge_left()"));
	if (l->num_ptrs + r->num_ptrs > NODE_CAPACITY)
		return (ft_error("Node capacity exceeded in merge_left()"));
	return (0);
}

t_tree		*merge_left(t_tree *left, t_tree *right)
{
	int		i;
	if (!input_error(left, right))
	{
		i = right->num_ptrs;
		while (i-- > 0)
		{
			printf("CALLING PASS LEFT FROM INSIDE MERGE LEFT\n");
			pass_ptr_left(left, right);
		}
		del_ptr_at(right->parent, get_index(right));
		update_keys(right->parent);
		del_node(right);
	}
	return (left);
}
