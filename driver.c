#include<stdio.h>
#include "node.h"

int main(int argc, char* argv[])
{
  printf("Hello, World\r\n");

  printf("Allocating some nodes\r\n");

  int i;
  for (i = 0; i < 100 ; i++)
  {
    int data = i;
    node * n = build_node(&data);
    printf("Node has the data %d\r\n", *(int*)n->data);
    destroy_node(n);
  }

  return 0;
}
