#include "../LinkedLists/SList.h"

void initStack(struct Node **top)
{
    *top = NULL;
    return;
}

int push(int data, struct Node **top)
{
  int flag;
  flag = prepend(data, top);
  return flag;
}

int pop(struct Node **top)
{
  int val;
  val = delFirstNode(top);

  return val;
}

int printStack(struct Node **top)
{
  int flag;
  flag = printList(top);

  return flag;
}
