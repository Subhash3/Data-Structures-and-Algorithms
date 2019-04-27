#include <stdio.h>
#include <stdlib.h>
#include "Node_Declaration.h"

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
