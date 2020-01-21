#include <stdio.h>
#include "Stack.h"

int main()
{
  struct Node *s;
  initStack(&s);

  int choice, val, flag;
  while(1)
  {
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Print.\n");
      printf("4. Exit.\n");
      printf("Enter ur choice: ");
      scanf("%d", &choice);

      switch(choice)
      {
          case 1 : printf("Enter a value: ");
		   scanf("%d", &val);
		   flag = push(val, &s);
		   if(!flag)
		   {
		       printf("\n[!!]Error while allocating memory.\n\n");
		   }
		   else
		   {
		       printf("\n[+] %d is pushed.\n\n", val);
		   }
		   break;
          case 2 : flag = pop(&s);
		   if(flag != INT_MAX)
		   {
		       printf("\n[-] %d is popped\n\n", flag);
		   }
		   else
		   {
		       printf("\n[!!]Stack is empty.\n");
		   }
		   break;
          case 3 : flag = printStack(&s);
		   if(!flag)
		   {
		       printf("[!!]Stack is empty.\n");
		   }
		   break;
          case 4 : printf("..Exiting...\n");
		   system("clear");
		   exit (0);
		   break;
          default: printf("Invalid choice.\n");
		   break;
      }
  }

  exit (0);
}
