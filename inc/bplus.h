/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bplus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 23:39:51 by irhett            #+#    #+#             */
/*   Updated: 2017/05/05 23:45:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PROBLEM IS IN MAKE-SPACE PASSING POINTERS TO PARENT
// OR NOT
#ifndef BPLUS_H
# define BPLUS_H

# include "libft.h"
# include <stdio.h> //

# define NODE_CAPACITY	4

typedef struct		s_leaf
{
	void			*data;
	void			*key;
}					t_leaf;

typedef struct		s_tree
{
	int				is_leaf:1;
	int				num_ptrs;
	void			**ptrs;
	void			**keys;
	struct s_tree	*parent;
}					t_tree;

/*typedef struct		s_query
{
	t_list			*params;
	void			*function;
}					t_query; */

// add_leaf.c
t_tree				*add_leaf(t_tree *rt, t_leaf *l, int (*f)(void *, void *));

// can_pull.c
int					can_pull_from_right(t_tree *node);
int					can_pull_from_left(t_tree *node);

// can_share.c
int					can_share(t_tree *node);

// condense.c
t_tree				*condense(t_tree **root, t_tree *nodes);

// del_ptr_at.c
void				*del_ptr_at(t_tree *node, int index);

// for_each_tree_node.c
// a depth-first traversal that applies function f to each node
void				for_each_tree_node(t_tree **node, void *(*f)(void *));

// get_first_of_key.c
int					get_first_of_key(t_tree *n, void *key, int (*c)(void *, void *));

// get_edge_child.c
t_tree				*get_leftmost_child(t_tree *node, int level);
t_tree				*get_rightmost_child(t_tree *node, int level);

// get_index.c
int					get_index_of_self(t_tree *node);
int					get_index_of_child(t_tree *parent, t_tree *child);

// get_leaf.c
t_leaf				*get_leaf(t_tree *rt, void *k, int (*f)(void *, void *));

// get_neighbor.c
t_tree				*get_left(t_tree *node);
t_tree				*get_right(t_tree *node);

// ins_ptr_at.c
void				ins_ptr_at(t_tree *node, int index, void *ptr);

// ins_ptr_in_node.c
t_tree				*ins_ptr_in_node(t_tree *r, t_tree *n, void *ptr, int (*f)(void *, void *));

// is_full.c
int					is_full(t_tree *node);

// make_space.c
t_tree				*make_space(t_tree **root, t_tree *node, int force,
					int (*f)(void *, void *));

// merge.c
t_tree				*merge_left(t_tree *left, t_tree *right);
t_tree				*merge_right(t_tree *left, t_tree *right);

// new_empty_tree.c
t_tree				*new_empty_tree(void);

// pass_ptr.c
void				pass_ptr_left(t_tree *left, t_tree *right);
void				pass_ptr_right(t_tree *left, t_tree *right);

// remove.c
t_leaf *remove(t_tree **root, void *key, int (*f)(void *, void *));

// TODO DUPES! ^^ vv

// remove_leaf.c
// just removes a single node that matches a key, revise to be a list or array
t_leaf				*remove_leaf(t_tree **root, void *k, 
					int (*f)(void *, void *));

// rm_leaf.c
t_leaf				*rm_leaf(t_tree *node, int index);

// shift_ptrs.c

// split.c





// t_leaf.c
t_leaf				*new_leaf(void *data, void *key);
void				del_leaf(t_leaf *leaf);

// t_node.c
t_tree				*new_node(int is_leaf, t_tree *parent);
void				del_node(t_tree *node);

// update.c


// revise to be get_leaves and return t_list not t_leaf
// same for remove
t_leaf				*update_leaf(t_tree **root, void *k, t_leaf *leaf,
					int (*f)(void *, void *));

/*
** Helper Functions, generally not called directly.
*/


// NOTES.md stopped here

int					get_node_index(t_tree *node);
// HARD functions
// perform no key updates, just do the intended purpose

void				shift_ptrs_left(t_tree *node, int index);
void				shift_ptrs_right(t_tree *node, int index);
t_tree				*split_right(t_tree *left);

void				update_keys(t_tree *node);
void				*get_lowest_key(t_tree *node);
int					get_index_of_child(t_tree *parent, t_tree *child);
t_tree				*split_root(t_tree **root);
// ADD get_all
// ADD print_all
// ADD destroy_graph
///////////////////////////////////////////////////////////////////////

/*
 * come up with a linked-list of tree nodes outside of tree
 * or linked-list of t_leaf_datas
t_tree				*del_by(t_tree *head, void *key, int (*f)(void *, void *));
*/
//t_tree				*del_single_elem(t_tree **head, void *elem);

//void				tree_for_each(t_tree **h, void *(*f)(void *));


#endif
