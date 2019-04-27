#include <stdio.h>
#include <stdlib.h>
#include "myFiles.h"

#define ARR_LEN 100

void countingSort(int arr[], int nitems);
void stableCountingSort(int arr[], int nitems);
void radixSort(int digit[], int nitmes);
//void printMultiArr(int arr[][ARR_LEN], int row, int column);

int main()
{
  int n;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // Array with n elements
  int arr[n];

  readData(arr, n);
  printData(arr, n);
  stableCountingSort(arr, n);
  radixSort(arr, n);

  exit(0);
}
void countingSort(int arr[ARR_LEN], int n)
{
  int i, j, max;
  max = getMax(arr, n);

  // Count array to store the counts of each element
  int count[max+1];

  // Initialize count to 0
  for(i = 0; i <= max; i++)
  {
      count[i] = 0;
  }

  for(i = 0; i < n; i++)
  {
      count[arr[i]] += 1;
      //printf("count of %d is %d\n", arr[i], count[arr[i]]);
  }

  //printData(count, max+1);

  for(i = 0; i <= max; i++)
  {
      //printf("count[%d]: %d\n", i, count[i]);
      if(count[i] != 0)
      {
          for(j = 1; j <= count[i]; j++)
          {
              printf("%d, ", i);
          }
      }
  }
  printf("\n");

  return;
}

void stableCountingSort(int arr[ARR_LEN], int n)
{
  int i, j, max;

  max = getMax(arr, n);

  int count[max+1][max+1];

  for(i = 0; i <= max; i++)
  {
      for(j = 0; j <= max; j++)
      {
          count[i][j] = 0;
      }
  }

  for(i = 0; i < n; i++)
  {
      for(j = 0; j <= max; j++)
      {
          if(count[j][arr[i]] == 0)
	  {
              count[j][arr[i]] = 1;
	      break;
	  }
      }
  }

  // print sorted elements
  for(i = 0; i <= max; i++)
  {
      for(j = 0; j <= max; j++)
      {
          if(count[j][i] == 1)
	  {
	      printf("%d, ", i);
	  }
	  else
	  {
	      break;
	  }
      }
  }
  return;
}

void radixSort(int arr[ARR_LEN], int n)
{
  int i, digit[n];
  int place = 1;

  for(i = 0; i < n; i++)
  {
      digit[i] = (arr[i] / place) % 10;
  }
  place *= 10;

  printf("Digits: ");
  printData(digit, n);

  stableCountingSort(arr, n);
}

/*
void printMultiArr(int count[ARR_LEN][ARR_LEN], int row, int column)
{
  int i, j;

  for(i = 0; i < row; i++)
  {
      for(j = 0; j < column; j++)
      {
          printf("%d, ", count[i][j]);
      }
      printf("\n");
  }

  return;
}
*/
