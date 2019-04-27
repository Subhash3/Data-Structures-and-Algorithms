#include <stdio.h>
#include <stdlib.h>

//All constant defintions
#define MAX   1000

//function prototypes
void printData(int arr[], int nitems);
void readData(int arr[], int nitems);
void merge(int arr1[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int main()
{
  int nitems;

  printf("Enter the number of elements: ");
  scanf("%d", &nitems);
  int arr[nitems];

  readData(arr, nitems);
  printData(arr, nitems);
  mergeSort(arr, 0, nitems-1);

  exit(0);
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

void merge(int arr[MAX], int left, int mid, int right)
{
  int i, j, k;
  int len1 = mid-left-1, len2 = right-mid;
  int arr1[len1], arr2[len2];

  for(i = 0; i < len1; i++)
  {
      arr1[i] = arr[left+1];
  }
  for(j = 0; j < len2; j++)
  {
      arr2[j] = arr[mid+1+j];
  }
  i = 0;
  j = 0;
  k = 0;

  while(i < len1 && j < len2)
  {
      if(arr1[i] < arr2[j])
      {
          arr[k] = arr1[i];
	  i++;
	  k++;
      }
      else
      {
          arr[k] = arr2[j];
	  j++;
	  k++;
      }
  }

  while(i < len1)
  {
      arr[k] = arr1[i];
      i++;
      k++;
  }
  while(j < len2)
  {
      arr[k] = arr2[j];
      j++;
      k++;
  }

  printData(arr, len1+len2);
  return;
}

void mergeSort(int arr[MAX], int left, int right)
{
  int mid;

  if(left < right)
  {
      mid = (right+left)/2;
      mergeSort(arr, left, mid);
      mergeSort(arr, mid+1, right);
      merge(arr, left, mid, right);
  }

  return;
}
