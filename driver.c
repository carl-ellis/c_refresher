#include<stdio.h>
#include "node.h"
#include "queue.h"

int main(int argc, char* argv[])
{
	int i;

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


	return 0;
}
