/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_ptrs_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 23:00:07 by irhett            #+#    #+#             */
/*   Updated: 2017/05/04 23:07:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	input_error(t_tree *node, int index)
{
	if (!node)
		return (ft_error("NULL passed to shift_ptrs_left()"));
	if ((index < 0) || (index >= node->num_ptrs) || (index >= NODE_CAPACITY))
		return (ft_error("Invalid index passed to shift_ptrs_left()"));
	return (0);
}

void		shift_ptrs_left(t_tree *node, int index)
{
	int		i;

	if (!input_error(node, index))
	{
		i = index;
		while (i < node->num_ptrs)
		{
			node->ptrs[i] = node->ptrs[i + 1];
			i++;
		}
		node->ptrs[i] = NULL;
		node->num_ptrs--;
	}
}
