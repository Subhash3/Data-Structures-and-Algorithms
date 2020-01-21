#include "Queue.h"

int main()
{
  int flag, choice, val;
  struct Node *q;

  initQueue(&q);

  while(1)
  {
      printf("1. Enqueue.\n");
      printf("2. Dequeue.\n");
      printf("3. Print queue.\n");
      printf("4. Exit.\n");
      printf("What to do: ");
      scanf("%d", &choice);

      switch(choice)
      {
	  case 1 : printf("Enter an element: ");
		   scanf("%d", &val);
                   flag = enQueue(val, &q);
		   if(flag)
		   {
		       printf("\n[+] Enqueued %d\n\n", val);
		   }
		   else
		   {
		       printf("\n[!!]Error while allocating memory\n\n");
		   }
                   break;
	  case 2 : flag = deQueue(&q);
		   if(flag == INT_MAX)
		   {
		       printf("\n[!!]List is Empty.\n\n");
		       break;
		   }
		   printf("\n[-] DeQueued %d\n\n", flag);
		   break;
	  case 3 : flag = printQueue(&q);
		   if(!flag)
		   {
		       printf("\n[!!] Queue is empty.\n\n");
		   }
		   break;
	  case 4 : exit(0);
	  default: printf("\n[!!] Invalid Choice\n\n");
		   break;
      }
  }
}
