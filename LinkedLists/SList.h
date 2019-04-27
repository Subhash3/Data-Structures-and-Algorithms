#include <stdio.h>
#include <stdlib.h>
#include <values.h>

struct Node
{
  int info;
  struct Node *link;
};

typedef struct Node SList;

// Function prototypes
void initList(struct Node **head);
int isEmpty(struct Node **head);
int prepend(int data, struct Node **head);
int append(int data, struct Node **head);
int insertAfter(int key, int data, struct Node **head);
int delFirstNode(struct Node **head);
int delLastNode(struct Node **head);
int deleteNode(int key, struct Node **head);
int printList(struct Node **head);
int reverseList(struct Node **head);
void clrScr();

void initList(struct Node **head)
{
  *head = NULL;

  return;
}

int isEmpty(struct Node **head)
{
  //printf("In is empty finc.\n");
  //printf("Comaparing head with Null\n");
  if(*head == NULL)
  {
      return 1;
  }
  return 0;
}

int prepend(int data, struct Node **head)
{
  //printf("In prepend.\n");

  struct Node *temp;

  temp = (struct Node*)malloc(sizeof(struct Node*));
  if(temp == NULL)
  {
      return 0;
  }
  temp->link = *head;
  temp->info = data;
  *head = temp;

  return 1;
}

int append(int data, struct Node **head)
{
  //printf("In append.\n");
  int flag;

  if(isEmpty(head))
  {
      //printf("List is empty.!!.. Calling prepend.\n");
      flag = prepend(data, head);
      return flag;
  }

  struct Node *ptr = *head;

  while(ptr->link != NULL)
  {
      ptr = ptr->link;
  }

  struct Node *temp;

  temp = (struct Node*)malloc(sizeof(struct Node*));
  if(temp == NULL)
  {
      return 0;
  }

  temp->link = NULL;
  temp->info = data;
  ptr->link = temp;

  return 1;
}

int printList(struct Node **head)
{
  if(isEmpty(head))
  {
      return 0;
  }

  struct Node *ptr = *head;
  int printed = 0;

  printf("\nList looks like:\n*");
  while(ptr != NULL)
  {
      printf("%d -> ", ptr->info);
      printed++;
      ptr = ptr->link;
  }
  printf("NULL\n\n");

  return printed;
}

int insertAfter(int key, int data, struct Node **head)
{
  struct Node* ptr = *head;
  int found = 0;

  if(isEmpty(head))
  {
      return -2;
  }

  while(ptr != NULL)
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

int deleteNode(int key, struct Node **head)
{
  if(isEmpty(head))
  {
      return -1;
  }

  struct Node *ptr = *head, *prev = *head;
  int found = 0;

  // Only One Node
  if(ptr->link == NULL)
  {
      *head = NULL;
      free(ptr);
      return 1;
  }

  while(ptr != NULL)
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

void clrScr()
{
  system("clear");
  printf("=============================\n");
  return;
}

int delFirstNode(struct Node **head)
{
  if(isEmpty(head))
  {
      return INT_MAX;
  }

  int val = (*head)->info;

  // only one node
  //struct Node *tmp = *head;
  if((*head)->link == NULL)
  {
      free(*head);
      *head = NULL;

      return val;
  }

  struct Node *tmp = *head;
  *head = tmp->link;
  free(tmp);

  return val;
}

int delLastNode(struct Node **head)
{
  if(isEmpty(head))
  {
      return INT_MAX;
  }

  int val;

  // Only one node
  if((*head)->link == NULL)
  {
      val = (*head)->info;
      free(*head);
      *head = NULL;
      return val;
  }

  struct Node *cur = *head, *prev = *head;
  while(cur->link != NULL)
  {
      prev = cur;
      cur = cur->link;
  }

  prev->link = cur->link;
  val = cur->info;
  free(cur);

  return val;
}

int reverseList(struct Node **head)
{
  if(isEmpty(head))
  {
      return 0;
  }

  if((*head)->link == NULL)
  {
      return 1;
  }

  struct Node *cur = *head, *prev = *head;
  cur = cur->link;
  prev->link = NULL;
  *head = cur;

  while(cur != NULL)
  {
      *head = cur->link;
      cur->link = prev;
      prev = cur;
      cur = *head;
  }
  *head = prev;

  return 1;
}
