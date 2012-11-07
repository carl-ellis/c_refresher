#include<stdio.h>
#include "node.h"
#include "queue.h"
#include "stack.h"
#include "linkedlist.h"
#include "tree.h"

/* Simple comparison function for trees with integers */
int tree_int_comp(tree * a, tree * b)
{
	int diff = *(int*)b->data - *(int*)a->data;
	if (diff < 0)
	{
		return -1;
	}
	else if(diff == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc, char* argv[])
{
	int i;
	node * m;

	/* obligatory */
	printf("Hello, World\r\n");
	printf("\r\n---\r\n");

	/* Node stuff */

	printf("Creating and destroying 10000 nodes\r\n");
	for (i = 0; i < 10000 ; i++)
	{
		int data = i;
		node * n = build_node(&data);
		destroy_node(n);
	}
	printf("Done\r\n");

	printf("\r\n---\r\n");

	printf("Building a queue, adding 10000 nodes. Printing out every 1000\r\n");
	queue * q = build_queue();

	for (i = 0; i < 10000 ; i++)
	{
		int data = i;
		node * n = build_node(&data);
		queue_push(q, n);
	}
	printf("Queue has the size %d\r\n", q->size);

	for (i = 0; i < 10000 ; i++)
	{
		node * n = queue_pop(q);
		if((i%1000)==0)
		{
			printf("Node has the data %d\r\n", *(int*)n->data);
		}
		destroy_node(n);
	}
	printf("Queue has the size %d\r\n", q->size);

	destroy_queue(q);
	printf("\r\n---\r\n");

	printf("Building a stack, adding 10000 nodes. Printing out every 1000\r\n");
	stack * s = build_stack();

	for (i = 0; i < 10000 ; i++)
	{
		int data = i;
		node * n = build_node(&data);
		stack_push(s, n);
	}
	printf("Stack has the size %d\r\n", s->size);

	for (i = 0; i < 10000 ; i++)
	{
		node * n = stack_pop(s);
		if((i%1000)==0)
		{
			printf("Node has the data %d\r\n", *(int*)n->data);
		}
		destroy_node(n);
	}
	printf("Stack has the size %d\r\n", s->size);

	destroy_stack(s);
	printf("\r\n---\r\n");
	
	printf("Building a linked list, adding 10000 nodes. Printing out every 1000\r\n");
	llist * l = build_llist();

	for (i = 0; i < 10000 ; i++)
	{
		int data = i;
		node * n = build_node(&data);
		llist_add(l, n);
	}
	printf("llist has the size %d\r\n", l->size);
	
	printf("Testing arbitrary access...\r\n");
	m = llist_get(l, 87);
  printf("Node has the data %d\r\n", *(int*)m->data);
  m = llist_get(l, 3487);
  printf("Node has the data %d\r\n", *(int*)m->data);
  m = llist_get(l, 287);
  printf("Node has the data %d\r\n", *(int*)m->data);
  
  printf("Testing arbitrary delete...\r\n");
  
  m = llist_get(l, 299);
  printf("Node has the data %d\r\n", *(int*)m->data);
  llist_delete(l, 299);
  m = llist_get(l, 299);
  printf("Node has the data %d\r\n", *(int*)m->data);

	printf("Testing mass delete...\r\n");
	destroy_llist(l);
	
	printf("\r\n---\r\n");
	
	printf("Creating and destroying 10000 single trees\r\n");
	for (i = 0; i < 10000 ; i++)
	{
		int data = i;
		tree * n = build_tree(&data);
		destroy_tree(n);
	}
	printf("Done\r\n");

	printf("\r\n---\r\n");
	
	printf("Testing add/delete for trees\r\n");
	int data = 2;
	tree * root = build_tree(&data);
	
	//for (i = 0; i < 3 ; i++)
//	{
//		int data = i;
//		tree * n = build_tree(&data);
//		destroy_tree(n);
//		add_leaf(&root, n, &tree_int_comp);
//	}
	
	data = 1;
	tree * leaf1 = build_tree(&data);
	add_leaf(&root, leaf1, &tree_int_comp);
	
	data = 0;
	tree * leaf2 = build_tree(&data);
	add_leaf(&root, leaf2, &tree_int_comp);
	
	printf("Root node has value %d before deletion\r\n", *(int*)root->data);
	delete_node(&(root));
	printf("Root node has value %d after deletion\r\n", *(int*)root->data);
	
	destroy_tree(leaf1);
	destroy_tree(leaf2);
	
	printf("Done\r\n");

	return 0;
}
