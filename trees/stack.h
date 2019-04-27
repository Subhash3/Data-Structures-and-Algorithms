#include <stdio.h>
#include <stdlib.h>
#include "Node_Declaration.h"

/*
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
};
typedef struct Node Node;
*/
struct SNode
{
  Node* data;
  struct SNode* next;
};

typedef struct SNode SNode;

//Function prototypes
void initStack(SNode **Top);
int push(SNode **Top, Node *data);
int push(SNode **Top, Node *data);
int printStack(SNode **Top);
int isStackEmpty(SNode **Top);

void initStack(SNode **Top)
{
  *Top = NULL;

  return;
}

int isStackEmpty(SNode **Top)
{
  if(*Top == NULL)
  {
      return 1;
  }
  return 0;
}

int push(SNode **Top, Node *data)
{
  SNode *temp;
  temp = (SNode *)malloc(sizeof(SNode*));
  if(temp == NULL)
  {
      return 0;
  }
  temp->data = data;
  temp->next = *Top;
  *Top = temp;

  return 1;
}

Node* pop(SNode **Top)
{
  Node* info;
  if(isStackEmpty(Top))
  {
      return NULL;
  }

  SNode *ptr = *Top;
  // Only one node
  if((*Top)->next == NULL)
  {
      info = (*Top)->data;
      free(ptr);
      *Top = NULL;
      return info;
  }

  info = ptr->data;
  *Top = (*Top)->next;
  free(ptr);

  return info;
}

int printStack(SNode **Top)
{
  SNode *ptr = *Top;

  if(isStackEmpty(Top))
  {
      return 0;
  }

  printf("\n*");
  while(ptr != NULL)
  {
      printf("%d->", ptr->data->data);
      ptr = ptr->next;
  }
  printf("NULL\n\n");

  return 1;
}
