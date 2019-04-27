#include <stdio.h>
#include <stdlib.h>

#define MAX   100

void readData(int arr[], int nitems);
void printData(int arr[], int nitems);
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int arr[MAX], int *a, int *b);

int main()
{
  int nitems;

  printf("Enter the number of elements: ");
  scanf("%d", &nitems);

  int arr[nitems];
  readData(arr, nitems);
  printData(arr, nitems);
  quickSort(arr, 0, nitems);
  printf("After Sorting, ");
  printData(arr, nitems);
}

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

void quickSort(int arr[MAX], int low, int high)
{
  int pivot;

  if(low < high)
  {
      pivot = partition(arr, low, high);
      quickSort(arr, low, pivot-1);
      quickSort(arr, pivot+1, high);
  }

  return;
}

int partition(int arr[MAX], int low, int high)
{
  int left, right;
  int pivotItem;
  //int pivot;

  pivotItem = arr[low];

  left = low;
  right = high;

  while(left < right)
  {
      while(arr[left] <= pivotItem) left++;
      while(arr[right] > pivotItem) right--;

      if(left < right)
      {
          swap(arr, &left, &right);
      }
  }

  arr[low] = arr[right];
  arr[right] = pivotItem;
  return right;
}

void swap(int arr[MAX], int *a, int *b)
{
  int temp;

  temp = arr[*a];
  arr[*a] = arr[*b];
  arr[*b] = temp;

  return;
}
