#ifndef NODE_H
#define NODE_H

/* structure of a node for use by queues and stacks */
typedef struct node_t {
  struct node_t * next;
  int size;
  void * data;
} node;

/* returns a node given some data. Allocated in the method. */
node * build_node(void * data);

/* destroys a node, unallocs the data from in the node */
void destroy_node(node * node_data);

#endif
