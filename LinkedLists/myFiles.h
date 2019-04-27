#define MAX 100
#include "Stack.h"
#include "SList.h"

void readData(int arr[MAX], int nitems)
{
  int i;

  for(i = 0; i < nitems; i++)
  {
      printf("> ");
      scanf("%d", &arr[i]);
  }

  return;
}

void printData(int arr[MAX], int nitems)
{
  int i;

  printf("Array looks like: \n");
  for(i = 0; i < nitems; i++)
  {
      printf("%d, ", arr[i]);
  }
  printf("\b\b\n");

  return;
}

int getMax(int arr[MAX], int nitems)
{
  int i, max;

  max = arr[0];  
  for(i = 1; i < nitems; i++)
  {
      if(arr[i] > max)
      {
          max = arr[i];
      }
  }

  return max;
}
/*
void printMultiArr(int arr[MAX][MAX], int row, int column)
{
  int i, j;

  for(i = 0; i < row; i++)
  {
      for(j = 0; j < column; j++)
      {
          printf("%d, ", arr[i][j]);
      }
      printf("\n");
  }
  printf("\n");

  return;
}
*/
