#include<stdlib.h>
#include<string.h>
#include "node.h"


/* returns a node given some data. Allocated in the method. */
node * build_node(void * data)
{

  /* allocate node memory */
  node * node_ptr = (node*)malloc(sizeof(node));

  /* assign data size */
  node_ptr->size = sizeof(data);

  /* assign fresh memory and copy over the data */
  void * node_ptr_data = malloc(node_ptr->size);
  memcpy(node_ptr_data, data, node_ptr->size);
  node_ptr->data = node_ptr_data;

  return node_ptr;
}

/* destroys a node, unallocs the data from in the node */
void destroy_node(node * node_data)
{
  free(node_data->data);
  free(node_data);
}

