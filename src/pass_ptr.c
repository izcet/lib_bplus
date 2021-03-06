/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:55:59 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:10:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

void	pass_ptr_left(t_tree *left, t_tree *right)
{
	if (!left || !right)
		ft_error("NULL passed to pass_ptr_left()");
	ins_ptr_at(left, left->num_ptrs, del_ptr_at(right, 0));
	update_keys(left); // not needed?
}

void	pass_ptr_right(t_tree *left, t_tree *right)
{
	if (!left || !right)
		ft_error("NULL passed to pass_ptr_right()");
	ins_ptr_at(right, 0, del_ptr_at(left, left->num_ptrs - 1));
	update_keys(right);
}
