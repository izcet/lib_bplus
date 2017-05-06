/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_leaf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:25:50 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 20:25:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(void **r, void *k, void *l, void *f)
{
	if (!r || !(*r) || !k || !l || !f)
		return (ft_error("NULL passed to update_leaf()"));
	return (0);
}

t_leaf		*update_leaf(t_tree **root, void *k, t_leaf *leaf,
		int (*f)(void *, void *))
{
	t_leaf	*ret;

	ret = remove_leaf(root, k, f);
	if (ret)
	{
		*root = add_leaf(*root, leaf, f);
		return (ret);
	}
	return (NULL);
}
