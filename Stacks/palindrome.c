#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
#define STR_LEN 100

void push(char c);
char pop();

struct stack
{
  char arr[STACK_SIZE];
  int top;
};

struct stack s;

int main()
{
  char str[STR_LEN];
  int i, len, mid, check = 1;
  s.top = -1; // Initially stack points to -1

  printf("Enter a string: ");
  scanf("%s", str);

  len = strlen(str);
  mid = len/2;

  for(i = 0; i < mid; i++)
  {
      push(str[i]);
  }
  if(len % 2 == 0)
  {
  for(i = mid; i < len; i++)
  {
      if(str[i] != pop())
      {
          check = 0;
	  break;
      }
  }
  }
  else
  {
  
  for(i = mid+1; i < len; i++)
  {
      if(str[i] != pop())
      {
          check = 0;
	  break;
      }
  }
  }
  if(check == 1)
  {
      printf("Yes\n");
  }
  else
  {
      printf("No\n");
  }
}


void push(char c)
{
  if(s.top == STACK_SIZE)
  {
      printf("Stack is full.\n");
      return;
  }
  s.top++;

  s.arr[s.top] = c;
  
  return;
}

char pop()
{
  if(s.top == -1)
  {
      printf("Stack is empty\n");
      exit(0);
  }

  return s.arr[s.top--];
}
