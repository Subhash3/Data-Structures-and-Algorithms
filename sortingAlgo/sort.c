#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARR_LEN 1024

//Function prototypes
void readData(int arr[], int nitems);
void printData(int arr[], int nitems);
void swap(int *a, int *b);
int findMinIndex(int arr[], int start, int end);
void bubbleSort(int arr[], int nitems);
void selectionSort(int arr[], int nitems);
void insertionSort(int arr[], int nitems);

int main()
{
  int arr[ARR_LEN], nitems, choice;

  printf("Enter the no. of elements: ");
  scanf("%d", &nitems);
  readData(arr, nitems);
  printf("Given ");
  printData(arr, nitems);
  
  printf("\n1. Bubble sort\n");
  printf("2. Selection sort\n");
  printf("3. Insertion sort\n");
  printf("Select what to do: ");
  scanf("%d", &choice);

  switch(choice)
  {
      case 1 : bubbleSort(arr, nitems);
	       printf("After sorting, ");
	       printData(arr, nitems);
	       break;
      case 2 : selectionSort(arr, nitems);
	       printf("After sorting, ");
	       printData(arr, nitems);
	       break;
      case 3 : insertionSort(arr, nitems);
	       printf("After sorting, ");
	       printData(arr, nitems);
	       break;
      default: printf("Invalid choice!!\n");
	       break;
  }

  exit (0);
}

void readData(int arr[ARR_LEN], int nitems)
{
  int i;

  printf("Enter the elements:\n");
  for(i = 0; i < nitems; i++)
  {
      printf("> ");
      scanf("%d", &arr[i]);
  }

  return;
}

void printData(int arr[ARR_LEN], int nitems)
{
  int i;

  printf("Array looks like:\n");
  for(i = 0; i < nitems; i++)
  {
      printf("%d, ", arr[i]);
  }
  printf("\b\b\n");

  return;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;

  return;
}

int findMinIndex(int arr[ARR_LEN], int start, int end)
{
  int i, min, minIndex = start;

  min = arr[start];
  for(i = start; i < end; i++)
  {
      if(arr[i] < min)
      {
          minIndex = i;
	  min = arr[i];
      }
  }

  return minIndex;
}

void bubbleSort(int arr[ARR_LEN], int nitems)
{
  int i;
  int unBubbled = nitems;

  while(unBubbled != 0)
  {
      for(i = 0; i < nitems; i++)
      {
          if(i >= unBubbled-1)
          {
              break;
          }
          if(arr[i] > arr[i+1])
          {
              swap(&arr[i], &arr[i+1]);
          }
      }
      unBubbled--;
  }
  return;
}

void selectionSort(int arr[ARR_LEN], int nitems)
{
  int i, minIndex;

  for(i = 0; i < nitems-1; i++)
  {
      minIndex = findMinIndex(arr, i, nitems);
      if(i != minIndex)
      {
          swap(&arr[i], &arr[minIndex]);
      }
  }

  return;
}

void insertionSort(int arr[ARR_LEN], int nitems)
{
  int i, j;

  for(i = 1; i < nitems; i++)
  {
      for(j = i; j > 0; j--)
      {
          if(arr[j] < arr[j-1])
	  {
	      swap(&arr[j], &arr[j-1]);
	  }
	  else
	  {
	      break;
	  }
      }
  }

  return;
}
