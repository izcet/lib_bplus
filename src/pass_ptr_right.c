/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_ptr_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:55:59 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 16:15:57 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

void	pass_ptr_right(t_tree *left, t_tree *right)
{
	if (!left || !right)
		ft_error("NULL passed to pass_ptr_left()");
	else
		ins_ptr_at(right, 0, del_ptr_at(left, left->num_ptrs - 1));
}
