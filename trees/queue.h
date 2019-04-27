#include <stdio.h>
#include <stdlib.h>
#include "Node_Declaration.h"

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
};
typedef struct Node Node;

struct QNode
{
  Node *data;
  struct QNode* next;
};

typedef struct QNode QNode;

//Function prototypes
void initQueue(QNode **Head);
int enqueue(QNode **Head, Node *data);
int enqueue(QNode **Head, Node *data);
int printQueue(QNode **Head);
int isEmpty(QNode **Head);

void initQueue(QNode **Head)
{
  *Head = NULL;

  return;
}

int isEmpty(QNode **Head)
{
  if(*Head == NULL)
  {
      return 1;
  }
  return 0;
}

int enqueue(QNode **Head, Node *data)
{
  QNode *temp;
  temp = (QNode *)malloc(sizeof(QNode*));
  if(temp == NULL)
  {
      return 0;
  }
  temp->data = data;

  // Queue is empty
  if(*Head == NULL)
  {
      temp->data = data;
      temp->next = NULL;
      *Head = temp;
      return 1;
  }

  QNode *ptr = *Head;
  while(ptr->next != NULL)
  {
      ptr = ptr->next;
  }
  ptr->next = temp;
  temp->next = NULL;

  return 1;
}

Node* dequeue(QNode **Head)
{
  Node* info;
  if(isEmpty(Head))
  {
      return NULL;
  }

  QNode *ptr = *Head;
  // Only one node
  if((*Head)->next == NULL)
  {
      info = (*Head)->data;
      free(ptr);
      *Head = NULL;
      return info;
  }

  info = ptr->data;
  *Head = (*Head)->next;
  free(ptr);

  return info;
}

int printQueue(QNode **Head)
{
  QNode *ptr = *Head;

  if(isEmpty(Head))
  {
      return 0;
  }

  printf("\n");
  while(ptr != NULL)
  {
      printf("%d->", ptr->data->data);
      ptr = ptr->next;
  }
  printf("NULL\n\n");

  return 1;
}
