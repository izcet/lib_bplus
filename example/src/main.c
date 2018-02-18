/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:07:23 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:14:42 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int				comparator(void *one, void *two)
{
	return (ft_strcmp((char*)one, (char*)two));
}

void	print_db(t_tree *root)
{
	for_each_tree_node(&root, print_data);
}

t_tree	*single_entry(t_tree *root, void *data, void *key)
{
	t_leaf		*d;

	data = ft_strdup(data);
	key = ft_strdup(key);
	printf("ADDING NEW NODE (%s %s) |||||||||||||||||||||||||||||||||||||||||||||\n", data, key);
	d = new_leaf(data,key);
	root = add_leaf(root, d, comparator);
	printf("Return value for (%s, %s) is %p\n", data, key, root);
	//print_data(root);
	return (root);
}

t_tree	*make_db(t_tree *root)
{
	root = single_entry(root, "aa", "aa");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xk", "xk");	
	root = single_entry(root, "tt", "tt");	

	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	root = single_entry(root, "ac", "ac");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xl", "xl");	
	root = single_entry(root, "tt", "tt");	

	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	root = single_entry(root, "ad", "ad");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xm", "xm");	
	root = single_entry(root, "tt", "tt");	

	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xn", "xn");	
	root = single_entry(root, "tt", "tt");	

	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	root = single_entry(root, "ae", "ae");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xo", "xo");	
	root = single_entry(root, "tt", "tt");	

	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xp", "xp");	
	root = single_entry(root, "tt", "tt");	

	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	root = single_entry(root, "af", "af");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xq", "xq");	
	root = single_entry(root, "tt", "tt");	
	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xr", "xr");	
	root = single_entry(root, "tt", "tt");	
	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	root = single_entry(root, "af", "af");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xs", "xs");	
	root = single_entry(root, "tt", "tt");	
	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xt", "xt");	
	root = single_entry(root, "tt", "tt");	
	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	root = single_entry(root, "af", "af");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xu", "xu");	
	root = single_entry(root, "tt", "tt");	
	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xv", "xv");	
	root = single_entry(root, "tt", "tt");	
	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	root = single_entry(root, "ag", "ag");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xw", "xw");	
	root = single_entry(root, "tt", "tt");	
	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	root = single_entry(root, "ah", "ah");	
	root = single_entry(root, "bb", "bb");	
	root = single_entry(root, "cc", "cc");	
	root = single_entry(root, "xx", "xx");	
	root = single_entry(root, "tt", "tt");	
	root = single_entry(root, "nn", "nn");	
	root = single_entry(root, "ab", "ab");	
	return (root);
}

int		main(int argc, char **argv)
{
	t_tree	*root;

	root = new_empty_tree();
	root = make_db(root);
	print_db(root);


	(void)argc;
	(void)argv;
	return (0);
}
