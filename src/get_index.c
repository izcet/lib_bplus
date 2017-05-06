/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:53:23 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:07:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *node)
{
	if (!node)
		return (ft_error("NULL passed to get_index()"));
	return (0);
}

int			get_index(t_tree *node)
{
	if (!input_error(node))
	{
		if (node->parent)
			return (get_index_of_child(node->parent, node));
	}
	return (-1);
}
