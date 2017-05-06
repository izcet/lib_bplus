/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_leaf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:06:30 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 19:10:36 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(void *r, void *k, void *f)
{
	if (!r || !k || !f)
		return (ft_error("NULL pointer passed to get_leaf()"));
	return (0);
}

t_leaf		*get_leaf(t_tree **root, void *key, int (*f)(void *, void *))
{
	int		i;

	if (check_for_errors(root, key, f))
		return (NULL);
	while (node && !(node->is_leaf))
	{
		i = get_first_of_key(node, key, f);
		if (i < 0)
			return (NULL);
		node = node->ptrs[i];
	}
	i = 0;
	while (i < node->num_ptrs && (f(key, ((t_leaf)(node->ptrs[i]))->key) != 0))
		i++;
	if (f(key, ((t_leaf)(node->ptrs[i]))->key) == 0)
		return (node->ptrs[i]);
	return (NULL);
}
