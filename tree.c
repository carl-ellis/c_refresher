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
	if((*cfunc)(*root, leaf) < 1)
	{
		add_leaf(&((*root)->left), leaf, cfunc);
	}
	else
	{
		add_leaf(&((*root)->right), leaf, cfunc);
	}
	
}

/* removes a tree node */
void delete_node(tree ** node)
{
	/* number of children */
	char num_child;
	
 	/* If node is null, ignore */
 	if (*node == 0x00)
 	{
	 return;
	}
 
 	/* Count children, not having a simple count allows encoding which branch is used in the value */
 	num_child = 0;
 	if ((*node)->right != 0x00)
 	{
 		num_child+=1;
 	}
 	if ((*node)->left != 0x00)
 	{
 		num_child+=2;
 	}
 	
  /* If node has no children, just remove */
  if (num_child == 0)
  {
  	destroy_tree(*node);
  	*node = 0x00;
  }
  /* If node has 1 child branch, just connect to the parent of root */
  else if (num_child == 1)
  {
  	tree * to_del = *node;
  	*node = (*node)->right;
  	destroy_tree(to_del);
  }
  else if (num_child == 2)
  {
  	tree * to_del = *node;
  	*node = (*node)->left;
  	destroy_tree(to_del);
  }
  /* Otherwise the tree has two children. To keep the binary tree fairly sane, 
	just shift the nodes suceessor (first child of greater branch to the nodes 
	position) to the current nodes position and delete the original successor. 
	Recursion will bubble values up until a single/nochildren node is found to 
	end the calls */
  else
  {
 	
  	/* manually free the data from the node being deleted as we need to 
		circumvent the whole node deletion function. No not do this if null, 
		as we only need to do this on the original node to be deleted. */
		if((*node)->data != 0x00)
		{
			free((*node)->data);
		}
		
		/* Move successor data into current node, wipe successors data to avoid 
		segfaults */
		(*node)->size = ((*node)->right)->size;
		(*node)->data = ((*node)->right)->data;
		((*node)->right)->data = 0x00;
		
		delete_node(&((*node)->right));
  }
  return;
}
