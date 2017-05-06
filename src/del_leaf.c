/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_leaf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:13:03 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:06:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

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
