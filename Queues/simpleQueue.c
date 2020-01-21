#include <stdio.h>
#include <stdlib.h>
#include <values.h>

#define MAX_SIZE 100

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
      }
  }
}

void initQueue(queue *q)
{
  q->front = 0;
  q->rear = -1;
  q->count = 0;
  
  return;
}

int enQueue(queue *q, int val)
{
  if(q->rear == MAX_SIZE-1)
  {
      return -1;
  }
  else
  {
      q->rear++;
      q->arr[q->rear] = val;
  }
  q->count++;
  return 1;
}

int deQueue(queue *q)
{
  int val;

  if(q->front == -1 || q-> count == 0)
  {
      //val = MAXINT;
      return -1;
  }
  else
  {
      val = q->arr[q->front++];
  }
  q->count--;
  return val;
}

int printQueue(queue *q)
{
  int i;

  if(q->rear == -1 || q->rear < q->front)
  {
      return -1;
  }
  printf("Queue looks like: \n");
  for(i = q->front; i <= q->rear; i++)
  {
      printf("%d, ", q->arr[i]);
  }
  printf("\b\b\n");
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
