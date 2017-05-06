/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 01:30:42 by irhett            #+#    #+#             */
/*   Updated: 2017/05/04 22:38:16 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbtree.h"

void	del_node(t_tree *node)
{
	if (node)
	{
		free(node->ptrs);
		free(node->keys);
		ft_bzero(node, sizeof(t_tree));
		free(node);
		node = NULL;
	}
	else
		ft_error("NULL passed to del_node()");
}
