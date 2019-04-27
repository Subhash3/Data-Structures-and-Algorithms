#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int info;
  struct Node *link;
};

// Function prototypes
void initList(struct Node *n, struct Node **head);
int isEmpty(struct Node* list, struct Node **head);
int insertAtBeg(struct Node* list, int data, struct Node **head);
int insertAtEnd(struct Node* list, int data, struct Node **head);
int insertAfter(struct Node* list, int key, int data, struct Node **head);
int deleteNode(struct Node *list, int key, struct Node **head);
int printList(struct Node* list, struct Node **head);

int main()
{
  struct Node list, *head;
  int choice, data, key, flag;

  initList(&list, &head);

  while(1)
  {
      printf("1.Add Node at the begining.\n");
      printf("2.Add at the end.\n");
      printf("3.Add after a Node.\n");
      printf("4.Delete a Node.\n");
      printf("5.Print List.\n");
      printf("6.Exit.\n");
      printf("Enter ur choice: ");
      scanf("%d", &choice);

      switch(choice)
      {
          case 1 : printf("Enter data: ");
		   scanf("%d", &data);
		   if(insertAtBeg(&list, data, &head))
		   {
		       printf("Successfully inserted.\n\n");
		   }
		   else
		   {
                       printf("Error while allocating memory.\n\n");
		   }
		   break;
          case 2 : printf("Enter data: ");
		   scanf("%d", &data);
		   if(insertAtEnd(&list, data, &head))
		   {
		       printf("Successfully inserted.\n\n");
		   }
		   else
		   {
                       printf("Error while allocating memory.\n\n");
		   }
		   break;
          case 3 : printf("Enter data: ");
		   scanf("%d", &data);
		   printf("Enter key after which you want to add: ");
		   scanf("%d", &key);
		   flag = insertAfter(&list, key, data, &head);
		   if(flag == 1)
		   {
		       printf("Successfully inserted.\n\n");
		   }
		   else if(flag == -1)
		   {
                       printf("Error while allocating memory.\n\n");
		   }
		   else if(flag == -2)
		   {
		       printf("List is empty.\n\n");
		   }
		   else if(flag == 0)
		   {
		       printf("Key not found in the list.\n\n");
		   }
		   break;
	  case 4 : printf("Enter the data of the Node to be deleted: ");
		   scanf("%d", &data);
		   flag = deleteNode(&list, data, &head);
		   if(flag == -1)
		   {
		       printf("List is empty.\n");
		   }
		   else if(flag == 0)
		   {
		       printf("Key not found in the list.\n");
		   }
		   else
		   {
		       printf("Node deleted successfully.\n");
		   }
		   break;
          case 5 : if(!printList(&list, &head))
		   {
		       printf("List is empty\n");
		   }
		   break;
          case 6 : printf("Exiting..");
		   exit (0);
          default: printf("Invalid choice.\n");
		   break;

      }
  }
  
  exit (0);
}

void initList(struct Node *n, struct Node **head)
{
  n->link = NULL;
  *head = NULL;

  return;
}

int isEmpty(struct Node* list, struct Node **head)
{
  if(*head == NULL)
  {
      return 1;
  }
  return 0;
}

int insertAtBeg(struct Node* list, int data, struct Node **head)
{
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

int insertAtEnd(struct Node* list, int data, struct Node **head)
{
  int flag;

  if(isEmpty(list, head))
  {
      flag = insertAtBeg(list, data, head);
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

int printList(struct Node* list, struct Node **head)
{
  if(isEmpty(list, head))
  {
      return 0;
  }

  struct Node *ptr = *head;
  int printed = 0;

  printf("\nList looks like:\n");
  while(ptr != NULL)
  {
      printf("%d, ", ptr->info);
      printed++;
      ptr = ptr->link;
  }
  printf("\b\b\n\n");

  return printed;
}

int insertAfter(struct Node* list, int key, int data, struct Node **head)
{
  struct Node* ptr = *head;
  int found = 0;

  if(isEmpty(list, head))
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

int deleteNode(struct Node *list, int key, struct Node **head)
{
  if(isEmpty(list, head))
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
