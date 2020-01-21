#include "../LinkedLists/SList.h"

void initQueue(struct Node **front)
{
    initList(front);

    return;
}

int enQueue(int val, struct Node **front)
{
  int flag;

  flag = prepend(val, front);
  return flag;
}

int deQueue(struct Node **front)
{
    int flag;

    flag = delLastNode(front);
    return flag;
}

int printQueue(struct Node **front)
{
  int flag = printList(front);

  return flag;
}
