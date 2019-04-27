#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "SList.h"

int main()
{
  //struct Node *list;
  SList *list;
  initList(&list);
  int n, i, val, j;

  printf("Enter n: ");
  scanf("%d", &n);

  for(i = 0; i < n; i++)
  {
      printf("Enter an element: ");
      scanf("%d", &val);
      append(val, &list);
  }
  //Link the last element to an element in the middle
  SList *tmp = list, *cur = list;
  i = 0;
  while(tmp->link != NULL)
  {
      if(i != n/2)
      {
          cur = cur->link;
	  i++;
      }
      tmp = tmp->link;
  }

  printList(&list);

  printf("tmp points to %d, and cur points to %d\n\n", tmp->info, cur->info);

  tmp->link = cur;

  i = 0;
  j = 0;
  SList* arr[n];
  tmp = list; 
  while(tmp->link != NULL)
  {
      printf("tmp is at %p->%d\n", tmp, tmp->info);
      printf("\tAddr array: \n");
      for(i = 0; i < j; i++)
      {
          printf("\t  Addr: %p\n", arr[i]);
          if(arr[i] == tmp)
	  {
	      printf("arr[%d]: %p, Loop is there at %p->%d.\n", i, arr[i], tmp, tmp->info);
	      return 0;
	  }
      }
      arr[j] = tmp;
      j++;
      tmp = tmp->link;

      sleep(1);
  }
  //printList(&list);

  exit (0);
}
