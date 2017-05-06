/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_ptr_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:55:59 by irhett            #+#    #+#             */
/*   Updated: 2017/05/04 22:41:10 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bplus.h"

void	pass_ptr_left(t_tree *left, t_tree *right)
{
	if (!left || !right)
		ft_error("NULL passed to pass_ptr_left()");
	else
		ins_ptr_at(left, left->num_ptrs, del_ptr_at(right, 0));
}
