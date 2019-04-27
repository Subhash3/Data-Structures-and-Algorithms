#include "queue.h"

int main()
{
  Node *Head;

  initQueue(&Head);
  int choice, flag, data;

  while(1)
  {
      printf("1. EnQueue.\n");
      printf("2. DnQueue.\n");
      printf("3. Print\n");
      printf("4. Exit\n");
      printf("Enter ur choie: ");
      scanf("%d", &choice);

      switch(choice)
      {
          case 1 : printf("Enter data to enqueue: ");
		   scanf("%d", &data);
		   flag = enqueue(&Head, data);
		   if(flag == 0)
		   {
		       printf("\n[!!] Cannot allocate memory\n\n");
		   }
		   else
		   {
		       printf("\n[+] %d is Enqueqed\n\n", data);
		   }
		   break;
          case 2 : printf("Enter data to enqueue: ");
		   flag = dequeue(&Head);
		   if(flag == -1)
		   {
		       printf("\n[!!] Queue is Empty\n\n");
		   }
		   else
		   {
		       printf("\n[-] %d is Dequeqed\n\n", flag);
		   }
		   break;
          case 3 : flag = printQueue(&Head);
		   if(flag == 0)
		   {
		       printf("\n Queue is Empty.\n\n");
		   }
		   break;
          case 4 : exit (0);
          default: printf("Invalid choice\n");
		   break;
      }
  }
}
