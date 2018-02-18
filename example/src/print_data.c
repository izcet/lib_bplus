/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:24:22 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 22:51:25 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

static void		print_datas(t_tree *node)
{
	int	i;

	i = 0;
	printf("Node has the datas:\n");
	while (i < node->num_ptrs)
	{
		printf("[%s](%p)\t", ((t_leaf*)node->ptrs[i])->data, node->ptrs[i]);
		i++;
	}
	printf("\n");
}

static void		print_keys(t_tree *node)
{
	int	i;

	i = 0;
	printf("Node has the keys:\n");
	while (i < node->num_ptrs - 1)
	{
		printf("[%s]\t", node->keys[i]);
		i++;
	}
	printf("\n");
}

void			*print_data(t_tree *node)
{
	if (!node)
		ft_error("NULL passed to print_data()");
	else
	{
		printf("{\n");
		printf("Node %p has %i datas.\n", node, node->num_ptrs);
		if (node->parent != NULL)
			printf("Node has a parent %p\n", node->parent);
		else
			printf("Node has no parent, root?\n");
		if (node->is_leaf)
		{
			printf("Node is a leaf\n");
			print_keys(node);
			print_datas(node);
		}
		else
		{
			printf("Node is a branch.\n");
			print_keys(node);
		}
	}
	printf("}\n");
	return (node);
}
