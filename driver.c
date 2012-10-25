#include<stdio.h>
#include "node.h"
#include "queue.h"
#include "stack.h"
#include "linkedlist.h"

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
	printf("Queue has the size %d\r\n", s->size);

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
	
	printf("Testing arbitrary access...");
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

	return 0;
}
