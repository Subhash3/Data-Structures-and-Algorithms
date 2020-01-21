#include <stdio.h>
#include <stdio.h>

#define MAX_LEN 100

struct Data
{
  int intData;
  char charData;
  char string[MAX_LEN];
  float floatData;
};

struct LNode
{
  struct Data info;
  struct Node *link;
};

typedef struct Node Node;

void initList(Node **Head);
int isListEmpty(Node **Head);
void destroyList(Node **Head);

int main()
{
  Node *Head;

  initList(&Head);
}

void initList(Node **Head)
{
  *Head = NULL;
  return;
}

int isListEmpty(Node **Head)
{
  if(*Head == NULL)
  {
      return 1;
  }
  return 0;
}

void destroyList(Node **Head)
{
  Node *tmp = *Head;

  while(tmp != NULL)
  {
      tmp = tmp->link;
      free(*Head);
      *Head = tmp;
  }

  return;
}
