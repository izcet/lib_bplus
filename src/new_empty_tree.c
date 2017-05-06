/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_empty_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:52:28 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:10:44 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

t_tree	*new_empty_tree(void)
{
	t_tree	*root;
	root = new_node(1, NULL);
	if (!root)
		return (NULL);
	return (root);
}
