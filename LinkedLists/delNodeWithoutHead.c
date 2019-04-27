#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
//#include "myDataStructs.h"

int main()
{
   SList *list, *temp, *cur;
   int i, val;

   initList(&list);

   for(i = 0; i < 5; i++)
   {
       printf("Enter an element: ");
       scanf("%d", &val);
       insertAtBeg(val, &list);
   }
   printList(&list);
   printf("Enter pointer element: ");
   scanf("%d", &val);

   for(temp = list; temp != NULL; temp = temp->link)
   {
       printf("Pointer to %d, is %p\n", temp->info, temp);
       if(temp->info == val)
       {
           break;
       }
   }
   printf("\nPointer to %d, is %p\n", temp->info, temp);

   cur = temp->link;
   temp->info = cur->info;
   temp->link = cur->link;
   free(cur);

   printList(&list);

   exit(0);
}
