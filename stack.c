#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "stack.h"

/* returns an empty stack. */
stack * build_stack()
{

	/* allocate stack memory */
	stack * s = (stack*)malloc(sizeof(stack));

	/* initial values */
	s->front = 0x00;
	s->back = 0x00;
	s->size = 0;
	return s;
}

/* destroys a stack */
void destroy_stack(stack * s)
{
	/* Make sure to clear any data still in the stack */
	while(s->size > 0)
	{
		free(stack_pop(s));
	}
	free(s);
}

/* add a node to the stack */
void stack_push(stack * s, node * n)
{
	/* if stack is empty */
	if(s->back == 0x00)
	{
		s->front = n;
		s->back = n;
	}
	else
	{

		/* Sanity check */
		if(s->front == 0x00)
		{
			printf("[Queue]:: Error. Back pointer is null in a non-empty stack.\r\n");
		}

		/* shift the back pointer to the new node */
		n->next = s->front;
		s->front = n;
	}

	/* adjust size */
	s->size++;
}

/* remove a node from the stack, NULL if empty */
node * stack_pop(stack * s)
{
	/* Check if empty, return null if so */
	if (s->back == 0x00)
	{
		return 0x00;
	}

	/* Pop Node from the front */
	node * n = s->front;

	/* adjust size */
	s->size--;

	/*Check if stack is now empty */
	if(s->size == 0)
	{
		s->front = 0x00;
		s->back = 0x00;
	}
	else
	{
		s->front = n->next;
	}

	return n;
}
