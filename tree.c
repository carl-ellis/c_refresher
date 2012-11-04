#include<stdlib.h>
#include<string.h>
#include "tree.h"

/* returns a node given some data. Allocated in the method. */
tree * build_tree(void * data)
{

	/* allocate node memory */
	tree * node_ptr = (tree*)malloc(sizeof(tree));

	/* assign data size */
	node_ptr->size = sizeof(data);

	/* assign fresh memory and copy over the data */
	void * node_ptr_data = malloc(node_ptr->size);
	memcpy(node_ptr_data, data, node_ptr->size);
	node_ptr->data = node_ptr_data;
	
	/* ensure leaf links are null */
	node_ptr->parent = 0x00;
	node_ptr->left = 0x00;
	node_ptr->right = 0x00;

	return node_ptr;
}

/* destroys a node, unallocs the data from in the node */
void destroy_tree(tree * node_data)
{
	free(node_data->data);
	free(node_data);
}

/* adds leaf nodes to a tree using a given comparison function */
void add_leaf(tree ** root, tree * leaf, tree_comp_func cfunc)
{
	/* If recursion has hit a null leaf, add the new leaf to the pointer */
	if(*root == 0x00)
	{
		*root = leaf;
		leaf->parent = *root;
		return;
	}
	
	/* Otherwise traverse the tree until a null node is found */
	if((*cfunc)(*root, leaf) == 0)
	{
		add_leaf(&((*root)->left), leaf, cfunc);
	}
	else
	{
		add_leaf(&((*root)->right), leaf, cfunc);
	}
	
}
