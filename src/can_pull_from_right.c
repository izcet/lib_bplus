/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_pull_from_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:36:00 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 16:33:57 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *node)
{
	if (!n)
		return (ft_error("NULL passed to can_pull_from_right()"));
	return (0);
}

int			can_pull_from_right(t_tree *node)
{
	if (!input_error(node))
		if (get_right(node))
			return (can_share(get_right(node)));
	return (0);
}