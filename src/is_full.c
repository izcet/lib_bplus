/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:50:43 by irhett            #+#    #+#             */
/*   Updated: 2017/05/04 22:40:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

int		is_full(t_tree *node)
{
	if (node)
	{
		if (node->num_ptrs == NODE_CAPACITY)
			return (1);
		return (0);
	}
	return (ft_error("NULL passed to is_full()"));
}
