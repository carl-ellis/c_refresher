#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include "queue.h"

typedef queue llist;

/* returns an empty llist. */
llist * build_llist();

/* destroys a llist */
void destroy_llist(llist * l);

/* add a node to the llist */
void llist_add(llist * l, node * n);

/* get a node from the llist at index ,
   null if index is out of bounds.
*/
node * llist_get(llist * l, int index);

/* delete a node from the llist at index */
void llist_delete(llist * l, int index);

#endif
