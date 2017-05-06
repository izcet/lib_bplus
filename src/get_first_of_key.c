/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_of_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:52:02 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:07:49 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

#define NP (node->ptrs[i])

static int	input_error(void *n, void *k, void *f)
{
	if (!n || !k || !f)
		return (ft_error("NULL passed to get_index_of_key()"));
	return (0);
}

// doesn't always work for duplicates

// IF LEAF : return index of match, or -1 if not in this node
// IF BRANCH : return index where most likely

int			get_first_of_key(t_tree *node, void *key, int (*f)(void *, void *))
{
	int		i;
	if (input_error(node, key, f))
		return (-1);
	i = 0;
	if (node->is_leaf)
	{
		while (i < node->num_ptrs && f(key, ((t_leaf*)NP)->key) > 0)
			i++;
		if (i == node->num_ptrs)
			return (-1);
		return (i);
	}
	else
	{
		while (i < node->num_ptrs && f(key, get_lowest_key(NP)) > 0)
			i++;
		if (i == node->num_ptrs)
			return (i - 1);
		if (i > 0 && f(key, get_lowest_key(NP)) < 0)
			return (i - 1);
		return (i);
	}
	return (i);
}
