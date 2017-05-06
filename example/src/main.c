/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:07:23 by irhett            #+#    #+#             */
/*   Updated: 2017/05/04 16:13:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int				comparator(void *one, void *two)
{
	return (ft_strcmp((char*)one, (char*)two));
}

void	print_db(t_tree *root)
{
	tree_for_each(&root, print_data);
}

void	single_entry(t_tree *root, void *data, void *key)
{
	t_leaf_data	*d;
	int			ret;

	//printf("Adding (%s, %s)\n", data, key);
	d = new_data(data,key);
	ret = add_elem(&root, d, comparator);
	//printf("Return value for (%s, %s) is %i\n", data, key, ret);
}

void	make_db(t_tree *root)
{
	single_entry(root, "aa", "aa");	
	single_entry(root, "bb", "bb");	
	single_entry(root, "cc", "cc");	
	single_entry(root, "xx", "xx");	
	single_entry(root, "tt", "tt");	
	single_entry(root, "nn", "nn");	
	single_entry(root, "ab", "ab");	
	single_entry(root, "aa", "aa");	
	single_entry(root, "bb", "bb");	
	single_entry(root, "cc", "cc");	
	single_entry(root, "xx", "xx");	
	single_entry(root, "tt", "tt");	
	single_entry(root, "nn", "nn");	
	single_entry(root, "ab", "ab");	
	single_entry(root, "aa", "aa");	
	single_entry(root, "bb", "bb");	
	single_entry(root, "cc", "cc");	
	single_entry(root, "xx", "xx");	
	single_entry(root, "tt", "tt");	
	single_entry(root, "nn", "nn");	
	single_entry(root, "ab", "ab");	
	single_entry(root, "aa", "aa");	
	single_entry(root, "bb", "bb");	
	single_entry(root, "cc", "cc");	
	single_entry(root, "xx", "xx");	
	single_entry(root, "tt", "tt");	
	single_entry(root, "nn", "nn");	
	single_entry(root, "ab", "ab");	
}

int		main(int argc, char **argv)
{
	t_tree	*root;

	root = new_graph();
	make_db(root);
	print_db(root);
}
