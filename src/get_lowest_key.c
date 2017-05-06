/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lowest_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:43:56 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 19:55:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *node)
{
	if (!node)
		return (ft_error("NULL passed to get_lowest_key()"));
	return (0);
}

void		*get_lowest_key(t_tree *node)
{
	if (input_error(node))
		return (NULL);
	if (node->is_leaf)
		return (((t_leaf *)(node->ptrs[0]))->key);
	else
		return (get_lowest_key(node->ptrs[0]));
}
