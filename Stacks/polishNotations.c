#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "myDataStructs.h"

#define MAX  100
#define numOperators 5

//Function prototypes
void toPrefix(char *exp);
void toPostfix(char * exp);
void postfixToInfix(char *exp);
void prefixToInfix(char *exp);
int evalPrefix(char *exp);
int evalPostfix(char * exp);
int isOperator(char ch);
void reverse(char *str, char *rev);

// All global variables
char operators[numOperators] = {'+', '-', '*', '/', '\0'};
stack opStack;

int main()
{
  int choice, val;
  char exp[MAX];

  initStack(&opStack);

  printf("\n1. Infix to Postfix.\n");
  printf("2. Infix to Prefix.\n");
  printf("3. Evaluate Postfix expression.\n");
  printf("4. Evaluate Prefix expression.\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice)
  {
      case 1 : printf("Enter an infix Expression: ");
               scanf("%s", exp);
	       toPostfix(exp);
               printf("\nPostfix: %s\n", exp);
               break;
      case 2 : printf("Enter an infix Expression: ");
               scanf("%s", exp);
               toPrefix(exp);
               printf("Prefix: %s\n", exp);
               break;
      case 3 : //toPostfix(exp);
	       printf("Enter a postfix Expression: ");
	       scanf("%s", exp);
	       val = evalPostfix(exp);
	       printf("After evaluation: %d\n", val);
	       break;
      case 4 : //toPrefix(exp);
	       printf("Enter a prefix expression: ");
	       scanf("%s", exp);
	       val = evalPrefix(exp);
	       printf("After evaluation: %d\n", val);
	       break;
      default: printf("Invalid choice!!\n");
               break;
  }

  exit (0);
}

void toPostfix(char exp[MAX])
{
  //printf("POSTFIX\n");

  int i, len, j = 0, top;
  char postfix[MAX], val, topOfStack;

  len = strlen(exp);

  for(i = 0; i < len; i++)
  {
          if(exp[i] == '(')
          {
              push(&opStack, exp[i]);
          }
	  else if(exp[i] == ')') 
	  {
              while(1)
              {
                  val = pop(&opStack);
                  if(val == '(')
                  {
                      break;
	          }
	      	  postfix[j++] = val;
              }
	  }
	  else if(exp[i] == '*' || exp[i] == '/')
	  {
	      if(opStack.top == -1)
	      {
                  push(&opStack, exp[i]);
		  //printf("Pushed: %c\n", exp[i]);
		  //printStack(&opStack);
	      }
	      else
	      {
                  while(1)
		  {
                      topOfStack = opStack.arr[opStack.top];
	              if(opStack.top != -1 && (topOfStack == '*' || topOfStack == '/'))
	              {
	                  postfix[j++] = pop(&opStack);
	                  //push(&opStack, exp[i]);
                      }
		      else
		      {
		          break;
		      }
		  }
		  push(&opStack, exp[i]);
	      }
	  }
	  /*
	  else if(exp[i] == '/') 
	  {
	      if(opStack.top == -1)
	      {
	          push(&opStack, exp[i]);
	      }
	      else
	      {
                  topOfStack = opStack.arr[opStack.top];
	          if(topOfStack == '*' || topOfStack == '/')
	          {
	              postfix[j++] = pop(&opStack);
	              //push(&opStack, exp[i]);
		  }
		  push(&opStack, exp[i]);
	      }
	  }*/
	  else if(exp[i] == '+' || exp[i] == '-')
	  {
	      top = opStack.top;
	      if(top == -1)
	      {
	          push(&opStack, exp[i]);
		  //printf("Pushed: %c\n", exp[i]);
		  //printStack(&opStack);
	      }
	      else
	      {
                  while(1)
		  {
                      topOfStack = opStack.arr[opStack.top];
		      //printStack(&opStack);
                      if(opStack.top != -1 && isOperator(topOfStack))
	              {
	                  postfix[j++] = pop(&opStack);
	                  //push(&opStack, exp[i]);
                      }
		      /*
		      if(topOfStack == -1)
		      {
		          break;
		      }*/
		      else
		      {
		          break;
		      }
		  }
		  push(&opStack, exp[i]);
	      }
	  }
	  /*
	  else if(exp[i] == '-')
	  {
	      if(opStack.top == -1)
	      {
	          push(&opStack, exp[i]);
	      }
	      else
	      {
                  topOfStack = opStack.arr[opStack.top];
	          if(isOperator(topOfStack))
	          {
	              postfix[j++] = pop(&opStack);
	              //push(&opStack, exp[i]);
		  }
		  push(&opStack, exp[i]);
	      }
	  }*/
	  else
	  {
	      postfix[j++] = exp[i];
	  }
          //printf("Postfix: %s\n", postfix);
  }

  while(opStack.top != -1)
  {
      postfix[j++] = pop(&opStack);
  }
  postfix[j++] = '\0';

  //printf("Nice: %s\n", postfix);
  strcpy(exp, postfix);
  return;
}

void toPrefix(char exp[MAX])
{
  int i, len, j = 0, top;
  char prefix[MAX], val, topOfStack, rev[MAX];

  reverse(exp, rev);
  strcpy(exp, rev);
  //printf("Reverse: %s\n", exp);
  len = strlen(exp);

  for(i = 0; i < len; i++)
  {
          if(exp[i] == '(')
          {
              push(&opStack, exp[i]);
          }
	  else if(exp[i] == ')') 
	  {
              while(1)
              {
                  val = pop(&opStack);
                  if(val == '(')
                  {
                      break;
	          }
	      	  prefix[j++] = val;
              }
	  }
	  else if(exp[i] == '*')
	  {
	      if(opStack.top == -1)
	      {
                  push(&opStack, exp[i]);
	      }
	      else
	      {
                  topOfStack = opStack.arr[opStack.top];
		  push(&opStack, exp[i]);
	      }
	  }
	  else if(exp[i] == '/') 
	  {
	      if(opStack.top == -1)
	      {
	          push(&opStack, exp[i]);
	      }
	      else
	      {
                  topOfStack = opStack.arr[opStack.top];
		  push(&opStack, exp[i]);
	      }
	  }
	  else if(exp[i] == '+')
	  {
	      top = opStack.top;
	      if(top == -1)
	      {
	          push(&opStack, exp[i]);
	      }
	      else
	      {
                  while(1)
		  {
                      topOfStack = opStack.arr[opStack.top];
		      if(opStack.top == -1)
		      {
		          break;
		      }
                      if(topOfStack == '*' || topOfStack == '/')
                      {
	                  prefix[j++] = pop(&opStack);
		      }
		      else
		      {
		          break;
		      }
		  }
		  push(&opStack, exp[i]);
	      }
	  }
	  else if(exp[i] == '-')
	  {
	      if(opStack.top == -1)
	      {
	          push(&opStack, exp[i]);
	      }
	      else
	      {
                  while(1)
		  {
                      topOfStack = opStack.arr[opStack.top];
		      if(opStack.top == -1)
		      {
		          break;
		      }
                      if(topOfStack == '*' || topOfStack == '/')
	              {
	                  prefix[j++] = pop(&opStack);
	                  //push(&opStack, exp[i]);
		      }
		      else
		      {
		          break;
		      }
		  }
		  push(&opStack, exp[i]);
	      }
	  }
	  else
	  {
	      prefix[j++] = exp[i];
	  }
  }

  while(opStack.top != -1)
  {
      prefix[j++] = pop(&opStack);
  }
  prefix[j++] = '\0';

  reverse(prefix, rev);
  strcpy(exp, rev);
  return;
}

int evalPostfix(char postfix[MAX])
{
  int i, num1, num2;

  printf("Postfix: %s\n", postfix);
  // Take an empty stack
  initStack(&opStack);

  for(i = 0; i < strlen(postfix); i++)
  {
      if(isdigit(postfix[i]))
      {
          push(&opStack, postfix[i]);
	  printStack(&opStack);
      }
      else
      {
          num1 = (int)(pop(&opStack)) -48;
	  printStack(&opStack);
          num2 = (int)(pop(&opStack)) -48;
	  printStack(&opStack);
	  printf("num1: %d, num2: %d\n", num1, num2);
          if(postfix[i] == '+')
	  {
	      //push(&opStack, (char)(num2+num1+48));
	      push(&opStack, num2+num1+48);
	      printf("pushed: %c\n", num2+num1+48);
	  }
	  else if(postfix[i] == '-')
	  {
	      //push(&opStack, (char)(num2-num1+48));
	      push(&opStack, num2-num1+48);
	      printf("pushed: %c\n", num2-num1+48);
	  }
	  else if(postfix[i] == '*')
	  {
	      //push(&opStack, (char)(num2*num1+48));
	      push(&opStack, num2*num1+48);
	      printf("pushed: %c\n", num2*num1+48);
	  }
	  else if(postfix[i] == '/')
	  {
	      //push(&opStack, (char)(num2/num1+48));
	      push(&opStack, num2/num1+48);
	      printf("pushed: %c\n", num2/num1+48);
	  }
	  printStack(&opStack);
      }
  }

  return (int)pop(&opStack) -48;
}

int evalPrefix(char prefix[MAX])
{
  int i, num1, num2;
  char rev[strlen(prefix)];
  
  reverse(prefix, rev);
  //printf("Reverse: %s\n", rev);
  strcpy(prefix, rev);

  //printf("Prefix: %s\n", prefix);
  // Take an empty stack
  initStack(&opStack);

  for(i = 0; i < strlen(prefix); i++)
  {
      if(isdigit(prefix[i]))
      {
          push(&opStack, prefix[i]);
	  //printStack(&opStack);
      }
      else
      {
          num2 = (int)(pop(&opStack)) -48;
	  //printStack(&opStack);
          num1 = (int)(pop(&opStack)) -48;
	  //printStack(&opStack);
	  //printf("num1: %d, num2: %d\n", num1, num2);
          if(prefix[i] == '+')
	  {
	      push(&opStack, (char)(num2+num1+48));
	      //printf("pushed: %c\n", (char)(num2+num1));
	  }
	  else if(prefix[i] == '-')
	  {
	      push(&opStack, (char)(num2-num1+48));
	      //printf("pushed: %c\n", (char)(num2-num1));
	  }
	  else if(prefix[i] == '*')
	  {
	      push(&opStack, (char)(num2*num1+48));
	      //printf("pushed: %c\n", (char)(num2*num1));
	  }
	  else if(prefix[i] == '/')
	  {
	      push(&opStack, (char)(num2/num1+48));
	      //printf("pushed: %c\n", (char)(num2/num1));
	  }
	  //printStack(&opStack);
      }
  }

  return (int)pop(&opStack) -48;
}


void reverse(char str[MAX], char rev[MAX])
{
  int i, len = strlen(str), j = 0;

  for(i = len-1; i >= 0; i--)
  {
      if(str[i] == '(')
      {
          rev[j++] = ')';
      }
      else if(str[i] == ')')
      {
          rev[j++] = '(';
      }
      else
      {
          rev[j++] = str[i];
      }
  }
  rev[j++] = '\0';

  return;
}

int isOperator(char ch)
{
  int i;

  for(i = 0; i < numOperators; i++)
  {
      if(operators[i] == ch)
      {
          return 1;
      }
  }

  return 0;
}
