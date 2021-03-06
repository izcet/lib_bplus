/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_leaf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:03:51 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:10:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

t_leaf	*new_leaf(void *data, void *key)
{
	t_leaf	*leaf;
	leaf = (t_leaf *)malloc(sizeof(t_leaf));
	if (!leaf)
		return (NULL);
	leaf->data = data;
	leaf->key = key;
	return (leaf);
}

void	del_leaf(t_leaf *leaf)
{
	if (leaf)
	{
		free(leaf);
		leaf = NULL;
	}
	else
		ft_error("NULL passed to del_leaf()");
}
