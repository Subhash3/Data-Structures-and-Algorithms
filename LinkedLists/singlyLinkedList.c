#include <stdio.h>
#include <stdlib.h>
#include <values.h>

struct Node
{
  int info;
  struct Node *link;
};

typedef struct Node Node;

// Function prototypes
void initList(Node **head);
void clearList(Node **head);
int isEmpty(Node **head);
int insertAtBeg(int data, Node **head);
int insertAtEnd(int data, Node **head);
int insertAfter(int key, int data, Node **head);
int deleteNode(int key, Node **head);
int delFirstNode(Node **head);
int delLastNode(Node **head);
int printList(Node **head);
int reverseList(Node **head);

int main()
{
  Node *head;
  int choice, data, key, flag;

  initList(&head);

  while(1)
  {
      printf("1.Add Node at the begining.\n");
      printf("2.Add at the end.\n");
      printf("3.Add after a Node.\n");
      printf("4.Delete a Node.\n");
      printf("5.Print List.\n");
      printf("6.Delete first node.\n");
      printf("7.Delete last node.\n");
      printf("8.Reverse the list.\n");
      printf("9.Clear Screen.\n");
      printf("10.Destroy List.\n");
      printf("11.Exit.\n");
      printf("Enter ur choice: ");
      scanf("%d", &choice);

      switch(choice)
      {
          case 1 : printf("Enter data: ");
		   scanf("%d", &data);
		   if(insertAtBeg(data, &head))
		   {
		       printf("\n[+] Successfully inserted.\n\n");
		   }
		   else
		   {
                       printf("\n[!!] Error while allocating memory.\n\n");
		   }
		   break;
          case 2 : printf("Enter data: ");
		   scanf("%d", &data);
		   if(insertAtEnd(data, &head))
		   {
		       printf("\n[+]Successfully inserted.\n\n");
		   }
		   else
		   {
                       printf("\n[!!] Error while allocating memory.\n\n");
		   }
		   break;
          case 3 : printf("Enter data: ");
		   scanf("%d", &data);
		   printf("Enter key after which you want to add: ");
		   scanf("%d", &key);
		   flag = insertAfter(key, data, &head);
		   if(flag == 1)
		   {
		       printf("\n[+] Successfully inserted.\n\n");
		   }
		   else if(flag == -1)
		   {
                       printf("\n[!!]Error while allocating memory.\n\n");
		   }
		   else if(flag == -2)
		   {
		       printf("\n[!!]List is empty.\n\n");
		   }
		   else if(flag == 0)
		   {
		       printf("\n[!!]Key not found in the list.\n\n");
		   }
		   break;
	  case 4 : printf("Enter the data of the Node to be deleted: ");
		   scanf("%d", &data);
		   flag = deleteNode(data, &head);
		   if(flag == -1)
		   {
		       printf("\n[!!]List is empty.\n\n");
		   }
		   else if(flag == 0)
		   {
		       printf("\n[!!]Key not found in the list.\n\n");
		   }
		   else
		   {
		       printf("\n[-] Node deleted successfully.\n\n");
		   }
		   break;
          case 5 : if(!printList(&head))
		   {
		       printf("\n[!!]List is empty\n");
		   }
		   break;
          case 6 : flag = delFirstNode(&head);
		   if(flag == INT_MAX)
		   {
		       printf("\n[!!]List is empty.\n\n");
		       break;
		   }
		   printf("\n[-] First Node (%d) has been Deleted.\n\n", flag);
		   break;
          case 7 : flag = delLastNode(&head);
		   if(flag == INT_MAX)
		   {
		       printf("\n[!!]List is empty.\n\n");
		       break;
		   }
		   printf("\n[-] Last Node (%d) has been Deleted.\n\n", flag);
		   break;
          case 8 : if(!reverseList(&head))
		   {
		       printf("\n[!!]List is empty.\n");
		       break;
		   }
		   printf("\n[*]List is reversed successfully.\n\n");
		   break;
          case 9 : system("clear");
                   printf("=============================\n"); 
		   break;
          case 10: clearList(&head);
		   printf("\nList is erased.\n\n");
		   break;
          case 11: printf("Exiting..\n");
		   system("clear");
		   exit (0);
          default: printf("\n[!!]Invalid choice.\n");
		   break;

      }
  }
  
  exit (0);
}

void initList(Node **head)
{
  *head = NULL;

  return;
}

int isEmpty(Node **head)
{
  if(*head == NULL)
  {
      return 1;
  }
  return 0;
}

int insertAtBeg(int data, Node **head)
{
  Node *temp;

  temp = (Node*)malloc(sizeof(Node*));
  if(temp == NULL)
  {
      return 0;
  }
  temp->link = *head;
  temp->info = data;
  *head = temp;

  return 1;
}

int insertAtEnd(int data, Node **head)
{
  int flag;

  if(isEmpty(head))
  {
      flag = insertAtBeg(data, head);
      return flag;
  }

  Node *ptr = *head;

  while(ptr->link != NULL)
  {
      ptr = ptr->link;
  }

  Node *temp;

  temp = (Node*)malloc(sizeof(Node*));
  if(temp == NULL)
  {
      return 0;
  }

  temp->link = NULL;
  temp->info = data;
  ptr->link = temp;

  return 1;
}

int printList(Node **head)
{
  if(isEmpty(head))
  {
      return 0;
  }

  Node *ptr = *head;
  int printed = 0;

  printf("\nList looks like:\n*");
  while(ptr != NULL)
  {
      printf("%d -> ", ptr->info);
      printed++;
      ptr = ptr->link;
  }
  printf("NuLL\n\n");

  return printed;
}

int insertAfter(int key, int data, Node **head)
{
  Node* ptr = *head;
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

  Node *temp;

  temp = (Node*)malloc(sizeof(Node*));
  if(temp == NULL)
  {
      return -1;
  }

  temp->link = ptr->link;
  temp->info = data;
  ptr->link = temp;

  return 1;
}

int deleteNode(int key, Node **head)
{
  if(isEmpty(head))
  {
      return -1;
  }

  Node *ptr = *head, *prev = *head;
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

int delFirstNode(Node **head)
{
  if(isEmpty(head))
  {
      return INT_MAX;
  }

  int val = (*head)->info;

  // only one node
  //Node *tmp = *head;
  if((*head)->link == NULL)
  {
      free(*head);
      *head = NULL;

      return val;
  }

  Node *tmp = *head;
  *head = tmp->link;
  free(tmp);

  return val;
}

int delLastNode(Node **head)
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

  Node *cur = *head, *prev = *head;
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

int reverseList(Node **head)
{
  if(isEmpty(head))
  {
      return 0;
  }

  if((*head)->link == NULL)
  {
      return 1;
  }

  Node *cur = *head, *prev = *head;
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

void clearList(Node **head)
{
  Node *ptr = *head;
  initList(head);
  if(isEmpty(head))
  {
      return;
  }
  Node *next = ptr->link;

  while(ptr != NULL)
  {
      free(ptr);
      ptr = next;
      if(next == NULL)
      {
          return;
      }
      next = next->link;
  }

  return;
}
