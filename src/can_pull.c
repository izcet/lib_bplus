/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_pull.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:36:00 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:05:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

static int	input_error(t_tree *node)
{
	if (!node)
		return (ft_error("NULL passed to can_pull_from_(left|right)()"));
	return (0);
}

int			can_pull_from_left(t_tree *node)
{
	if (!input_error(node))
		if (get_left(node))
			return (can_share(get_left(node)));
	return (0);
}

int			can_pull_from_right(t_tree *node)
{
	if (!input_error(node))
		if (get_right(node))
			return (can_share(get_right(node)));
	return (0);
}
