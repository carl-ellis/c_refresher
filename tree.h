#ifndef TREE_H
#define TREE_H

typedef struct tree_t
{
	struct tree_t * parent;
	struct tree_t * left;
	struct tree_t * right;
	int size;
	void * data;
} tree;

/* A comparison function to be used by the add leaf function.
	 must be of the form a < b == -1; a==b ==0; a > b == 1 */
typedef int (*tree_comp_func)(tree *,tree *);

/* returns a node given some data. Allocated in the method. */
tree * build_tree(void * data);

/* destroys a node, unallocs the data from in the node */
void destroy_tree(tree * node_data);

/* adds leaf nodes to a tree using a given comparison function */
void add_leaf(tree ** root, tree * leaf, tree_comp_func cfunc);

/* removes a tree node */
void delete_node(tree ** node);

#endif
