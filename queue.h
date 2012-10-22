#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

typedef struct queue_t
{
	node * front;
	node * back;
	int size;
} queue;

/* returns an empty queue. */
queue * build_queue();

/* destroys a queue */
void destroy_queue(queue * q);

/* add a node to the queue */
void queue_push(queue * q, node * n);

/* remove a node from the queue, NULL if empty */
node * queue_pop(queue * q);

#endif 
