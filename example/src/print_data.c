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
		ft_putstr(((t_leaf*)(node->ptrs[i]))->data);
		ft_putchar('\t');
		i++;
	}
	ft_putchar('\n');
}

static void		print_keys(t_tree *node)
{
	int	i;

	i = 0;
	printf("Node has the keys:\n");
	while (i < node->num_ptrs - 1)
	{
		ft_putstr(node->keys[i]);
		ft_putchar('\t');
		i++;
	}
	ft_putchar('\n');
}

void			*print_data(t_tree *node)
{
	ft_putendl("");
	if (!node)
		ft_error("NULL passed to print_data()");
	else
	{
		printf("Starting print_data()\n");
		printf("Node has %i datas.\n", node->num_ptrs);
		if (node->parent != NULL)
			printf("Node has a parent\n");
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
	return (node);
}
