#include <stdio.h>
#include <stdlib.h>
#include <values.h>

#define MAX_SIZE 4

typedef struct
{
  int front;
  int rear;
  int count;
  int arr[MAX_SIZE];
}queue;

// Function prototypes
void initQueue(queue *q);
int enQueue(queue *q, int val);
int deQueue(queue *q);
int printQueue(queue *q);

int main()
{
  queue q;
  int choice, val, flag;

  initQueue(&q);

  while(1)
  {
      printf("1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Print Queue\n");
      printf("4.Exit.\n");
      printf("What do you want to do: ");
      scanf("%d", &choice);

      switch(choice)
      {
          case 1 : printf("Enter an element to enqueue: ");
		   scanf("%d", &val);
		   flag = enQueue(&q, val);
		   if(flag == -1)
		   {
		       printf("Queue is Full, cannot insert\n");
		   }
		   break;
          case 2 : val = deQueue(&q);
		   if(val == -1)
		   {
		       printf("Queue is empty, cannot delete.\n");
		   }
		   else
		   {
		       printf("Dequeued %d from the queue.\n", val);
		   }
		   break;
          case 3 : flag = printQueue(&q);
		   if(flag == -1)
		   {
		       printf("Queue is empty.\n");
		   }
		   break;
          case 4 : exit(0);
		   break;
          default: printf("Invalid choice!!\n");
		   break;
      }
  }
}

void initQueue(queue *q)
{
  q->front = MAX_SIZE -1;
  q->rear = MAX_SIZE -1;
  q->count = 0;
  
  return;
}

int enQueue(queue *q, int val)
{
  if(q->rear == MAX_SIZE-1)
  {
      q->rear = 0;
  }
  else
  {
      q->rear++;
  }
  if(q->rear == q->front)
  {
      return -1;
  }
  if(q->rear == MAX_SIZE-1 && q->front == 0)
  {
      return -1;
  }
  q->arr[q->rear] = val;
  q->count++;
  return 1;
}

int deQueue(queue *q)
{
  if(q->count == 0)
  {
      //val = MAXINT;
      return -1;
  }
  if(q->front == MAX_SIZE -1)
  {
      q->front = 0;
  }
  else
  {
      q->front++;
  }

  q->count--;
  return q->arr[q->front];
}

int printQueue(queue *q)
{
  int t, printed = 0;

  if(q->count == 0)
  {
      return -1;
  }
  printf("Queue looks like: \n");

  t = q->front;
  while(1)
  {
      if(printed >= q->count)
      {
          break;
      }
      if(q->front == MAX_SIZE-1)
      {
          q->front = 0;
      }
      else
      {
          q->front++;
      }
      printf("%d, ", q->arr[q->front]);
      printed++;
  }
  printf("\b\b\n");
  q->front = t;
  return 1;
}
/*
int isEmpty(queue *q)
{
  if(q->rear == -1)
  {
      return 1;
  }
  else
  {
      return 0;
  }
}*/
