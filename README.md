# LIB B-PLUS 
### Overview
A B-Plus Tree data structure library written in C



### Structures


##### Macro NODE_CAPACITY
Defines the number of elements stored in each node.

##### Structure t_leaf
A reference to data.
- **data**: Pointer to where the full object is stored.
- **key**: Reference by which the leaves are sorted in the tree.

##### Structure t_tree
A single node in the tree.
- **is_leaf**: Boolean determining if the node is _leaf_ or _branch_. If _leaf_, then the **ptrs** will point to t_leaf
structs. Otherwise they will point to other nodes.
- **num_ptrs**: Number of elements in this node
- **ptrs**: Pointer array of the elements. (size: NODE_CAPACITY)
- **keys**: Pointer array of keys. (size: NODE_CAPACITY - 1)
- **parent**: Pointer to the parent of this node. Will be NULL if _root_ node.



### Functions


`t_tree		*new_empty_tree(void);`
- Allocates space for (and returns a pointer to) a new node. (Returns NULL on failure to allocate.)
- The new node will have no parent (_root_) and will have no data, but the arrays for **keys** and **ptrs** will be
allocated.
-usage:
```
...
t_tree	*root;

root = new_empty_tree();
...
```






`t_leaf		*new_leaf(void *data, void *key);`
- Allocateds space for (and returns a pointer to) a new leaf. (Returns NULL on failure to allocate.)
- Sets the pointers **data** and **key** to the input. 
- **PERFORMS NO CHECKS ON THE VALIDITY OF THE POINTERS**
- usage:
```
...
t_leaf	*leaf;

leaf = new_leaf(some_object, some_object->key);
...
```






`void	del_leaf(t_leaf *leaf)`
- De-allocates the memory of the given leaf.
- Does not handle the **data** and **key** of the given leaf
- usage:
```
...
t_leaf	*my_leaf;
...
if (i_am_done_with_this_data)
{
	free(my_leaf->data);
	free(my_leaf->key);
}
del_leaf(my_leaf);
...
```






`t_tree		*add_leaf(t_tree *root, void *l, int (*f)(void *, void *));`
- Adds a leaf to the given tree and returns a pointer to the new root.
- Root may change in the process of adding an element, by node splitting.
- Uses the given function pointer to sort the element **l** (_leaf_) into the tree.
-usage:
```
...
int		compare(void *a, void *b)
{
	// Sample terms of comparison. Don't actually use this criteria.
	if (a > b)
		return (1);
	if (a == b)
		return (0);
	return (-1);
}
...
t_tree	*root = new_empty_tree();
t_leaf	*leaf = new_leaf("blah", "blah");

root = add_leaf(root, leaf, compare);
...
```






`t_leaf		*get_leaf(t_tree *root, void *k, int (*f)(void *, void *));`
- Looks through the tree using **key** _k_ and function _f_.
- Returns the first matching leaf (the left-most element).
- Returns NULL if no matching leaf is found in the tree.
- usage:
```
...
void	*key = "blah";
t_leaf	*query;

query = get_leaf(root, key, compare);
if (!query)
	printf("Key %s not found.\n", key);
...
```






`t_leaf		*remove(t_tree **root, void *k, int (*f)(void *, void *));`
- Looks through the tree using **key _k_ and function _f_.
- Removes the first matching leaf (the left-most element) from the graph and returns it.
- Returns NULL if no matching leaf is found
- Updates the _root_ as necessary, so be sure to pass the address of root.
- usage:
```
...
void	*key = "oops";
t_leaf	*unwanted;
...
unwanted = remove(&root, key, compare);
...
del_leaf(unwanted);
...
```






`t_tree		*new_node(int is_leaf, t_tree *parent);`
- Allocates space for a single new empty node
- Allocates space for the empty arrays
- Sets the corresponding values for *is_leaf* and the **parent** pointer.
- Returns the pointer to the node upon success
- Returns NULL on failure to allocate the node or its arrays.
- usage:
```
t_tree	*node;
t_tree	*other_node;

node = new_node(0, NULL);
other_node = (1, node);

// Bad practice, do not try to manually set node positions as I have provided
// 		ample functions to streamline and maintain stability.
//		but you get the idea of how it works
...
```

