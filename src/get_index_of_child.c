/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_of_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:48:16 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 16:31:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

int		input_error(t_tree *p, t_tree *c)
{
	if (!p || !c)
		return (ft_error("NULL passed to get_index_of_child()"));
	return (0);
}

int		get_index_of_child(t_tree *parent, t_tree *child)
{
	int		i;

	if (!input_error(parent, child))
	{
		i = 0;
		while (i < parent->num_ptrs)
		{
			if (parent->ptrs[i] == child)
				return (i);
			i++;
		}
		ft_error("Child not found in get_index_of_child()");
	}
	return (-1);
}
