/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_share.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:46:35 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 16:35:13 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static int	input_error(t_tree *node)
{
	if (!node)
		return (ft_error("NULL passed to can_share()"));
	return (0);
}

int			can_share(t_tree *node)
{
	if (input_error(node))
		return (0);
	if (node->num_ptrs > (NODE_CAPACITY / 2))
		return (1);
	return (0);
}
