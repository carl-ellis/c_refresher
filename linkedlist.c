#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "linkedlist.h"

/* returns an empty llist. */
llist * build_llist()
{
  return build_queue();
}

/* destroys a llist */
void destroy_llist(llist * l)
{
  destroy_queue(l);
}

/* add a node to the llist */
void llist_add(llist * l, node * n)
{
  queue_push(l, n);
}

/* get a node from the llist at index */
node * llist_get(llist * l, int index)
{
  /* null if index is out of bounds */
  if (index < 0 || index >= l->size)
  {
    return 0x00;
  }
  
  /* traverse list until found. O(n) */
  node * n = l->front;
  while(index-- >= 0)
  {
    n = n->next;
  }
  
  /* return found node */
  return n;
  
}

/* delete a node from the llist at index */
void llist_delete(llist * l, int index)
{
  /* return if index is out of bounds */
  if (index < 0 || index >= l->size)
  {
    return;
  }
  
  /* two cases, index is 0, or index is larger than 0 but still valid.
    if 0, perform a pop, if not, traverse and cut out of the loop,.
    then destroy node */
  node * n = l->front;
  if (index == 0)
  {
    n = queue_pop(l);
    destroy_node(n);
  }
  else 
  {
    /* traverse list until at node BEFORE node to be removed */
    while(index-- >= 1)
    {
      n = n->next;
    }
    
    /* shift order, this will work even if the next is null */
    node * del = n->next;
    n->next = del->next;
    
    /* delete node */
    destroy_node(del);
  }
  l->size--;
}
