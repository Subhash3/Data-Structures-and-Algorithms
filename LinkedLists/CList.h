#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int info;
  struct Node *link;
};

typedef struct Node CList;

// Function prototypes
void initList(struct Node **last);
int isEmpty(struct Node **last);
int insertAtBeg(int data, struct Node **last);
int insertAtEnd(int data, struct Node **last);
int insertAfter(int key, int data, struct Node **last);
int deleteNode(int key, struct Node **last);
int printList(struct Node **last);

void initList(struct Node **last)
{
  *last = NULL;

  return;
}

int isEmpty(struct Node **last)
{
  if(*last == NULL)
  {
      return 1;
  }
  return 0;
}

int insertAtBeg(int data, struct Node **last)
{
  struct Node *temp, *ptr = *last;

  if(isEmpty(last))
  {
      temp = (struct Node*)malloc(sizeof(struct Node*));
      temp->info = data;
      ptr = temp;
      temp->link = ptr;
      *last = ptr;

      return 1;
  }

  temp = (struct Node*)malloc(sizeof(struct Node*));
  if(temp == NULL)
  {
      return 0;
  }
  temp->link = ptr->link;
  temp->info = data;
  ptr->link = temp;

  return 1;
}

int insertAtEnd(int data, struct Node **last)
{
  int flag;

  if(isEmpty(last))
  {
      flag = insertAtBeg(data, last);
      return flag;
  }

  struct Node *ptr = *last;
  struct Node *temp;

  temp = (struct Node*)malloc(sizeof(struct Node*));
  if(temp == NULL)
  {
      return 0;
  }

  temp->link = ptr->link;
  temp->info = data;
  ptr->link = temp;
  *last = temp;

  return 1;
}

int printList(struct Node **last)
{
  if(isEmpty(last))
  {
      return 0;
  }

  struct Node *head = *last, *ptr = head->link;
  int printed = 0, lastElement = head->info;
  head = head->link;

  printf("\nList looks like:\n");
  while(ptr != *last)
  {
      printf("%d, ", ptr->info);
      printed++;
      ptr = ptr->link;
  }
  printf("%d\n\n", lastElement);
  printed++;

  return printed;
}

int insertAfter(int key, int data, struct Node **last)
{
  struct Node* ptr = *last;
  ptr = ptr->link;
  int found = 0, flag;

  if(isEmpty(last))
  {
      return -2;
  }

  struct Node *tmp = *last;
  if(tmp->info == key)
  {
      flag = insertAtEnd(data, last);
      return flag;
  }

  while(ptr != *last)
  {
      if(ptr->info == key)
      {
          found = 1;
	  break;
      }
      ptr = ptr->link;
  }

  if(found == 0)
  {
      return 0;
  }

  struct Node *temp;

  temp = (struct Node*)malloc(sizeof(struct Node*));
  if(temp == NULL)
  {
      return -1;
  }

  temp->link = ptr->link;
  temp->info = data;
  ptr->link = temp;

  return 1;
}

int deleteNode(int key, struct Node **last)
{
  if(isEmpty(last))
  {
      return -1;
  }

  struct Node *ptr = *last, *prev = *last;
  ptr = ptr->link;
  int found = 0;

  // Only One Node
  if(ptr->link == ptr)
  {
      *last = NULL;
      free(ptr);
      return 1;
  }

  while(ptr != *last)
  {
      if(ptr->info == key)
      {
          found = 1;
	  break;
      }
      prev = ptr;
      ptr = ptr->link;
  }

  if(found == 0)
  {
      return 0;
  }

  prev->link = ptr->link;
  free(ptr);

  return 1;
}
