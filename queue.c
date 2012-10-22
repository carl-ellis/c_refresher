#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "queue.h"


/* returns an empty queue. */
queue * build_queue()
{
  /* allocate queue memory */
  queue * q = (queue*)malloc(sizeof(queue));

	/* initial values */
	q->front = 0x00;
	q->back = 0x00;
	q->size = 0;
	return q;
}

/* destroys a queue */
void destroy_queue(queue * q)
{
	/* Make sure to clear any data still in the queue */
	while(q->size > 0)
	{
		free(queue_pop(q));
	}
	free(q);
}

/* add a node to the queue */
void queue_push(queue * q, node * n)
{
	/* if queue is empty */
  if(q->front == 0x00)
	{
		q->front = n;
		q->back = n;
	}
	else
	{

		/* Sanity check */
	 	if(q->back == 0x00)
		{
			printf("[Queue]:: Error. Back pointer is null in a non-empty queue.\r\n");
		}

		/* shift the back pointer to the new node */
		q->back->next = n;
		q->back = n;
	}

	/* adjust size */
	q->size++;
}

/* remove a node from the queue, NULL if empty */
node * queue_pop(queue * q)
{
	/* Check if empty, return null if so */
	if (q->front == 0x00)
	{
		return 0x00;
	}
	
	/* Pop Node from the front */
	node * n = q->front;

	/* adjust size */
	q->size--;
	
	/*Check if queue is now empty */
	if(q->size == 0)
	{
		q->front = 0x00;
		q->back = 0x00;
	}
	else
	{
		q->front = n->next;
	}

	return n;
}

