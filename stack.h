#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct stack_t
{
	node * front;
	node * back;
	int size;
} stack;

/* returns an empty stack. */
stack * build_stack();

/* destroys a stack */
void destroy_stack(stack * s);

/* add a node to the stack */
void stack_push(stack * s, node * n);

/* remove a node from the stack, NULL if empty */
node * stack_pop(stack * s);

#endif 
