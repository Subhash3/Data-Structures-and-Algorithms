#include <stdio.h>
#include <stdlib.h>
#include "Queue_and_Stack.h"
/*
#include "queue.h"
#include "stack.h"
*/

// *-*-*-*-*- Delete is pending **-*-*-*-*-*-*
// Function prototypes
void initTree(Node **Root);
int isTreeEmpty(Node **Root);
int insertNode(Node **Root, int data);
int levelOrder(Node **Root);
int inOrder(Node **Root);
int preOrder(Node **Root);
int postOrder(Node **Root);
int deleteNode(Node **Root, int data);
int NodeType(Node **node);
Node* search(Node **Root, int data);

int main()
{
  Node *Root;
  initTree(&Root);
  int choice, data, flag;

  while(1)
  {
      printf("1. Insert Node.\n");
      printf("2. Delete Node.\n");
      printf("3. PreOrder\n");
      printf("4. InOrder\n");
      printf("5. PostOrder\n");
      printf("6. Level Order\n");
      printf("7. Exit\n");
      printf("Enter ur choice: ");
      scanf("%d", &choice);

      switch(choice)
      {
          case 1 : printf("Enter data to insert: ");
		   scanf("%d", &data);
		   insertNode(&Root, data);
		   break;
		   /*
          case 2 : printf("Enter key: ");
		   scanf("%d", &data);
		   flag = deleteNode(&Root, data);
		   if(flag == 0)
		   {
		       printf("Key not found.\n");
		   }
		   break;
		   */
	  case 3 : printf("Pre-Order:\n");
		   flag = preOrder(&Root);
		   if(flag == 0)
		   {
		       printf("tree isEmpty");
		   }
		   break;
          case 4 : printf("In-Order:\n");
		   flag = inOrder(&Root);
		   if(flag == 0)
		   {
		       printf("tree isEmpty");
		   }
		   break;
          case 5 : printf("Post-Order:\n");
		   flag = postOrder(&Root);
		   if(flag == 0)
		   {
		       printf("tree isEmpty");
		   }
		   break;
          case 6 : flag = levelOrder(&Root);
		   if(flag == 0)
		   {
		       printf("tree isEmpty");
		   }
		   break;
          case 7 : exit (0);
          default: printf("Invalid choice\n\n");
		   break;
      }
  }
}

void initTree(Node **Root)
{
  *Root = NULL;
  return;
}

int isTreeEmpty(Node **Root)
{
  if((*Root) == NULL)
  {
      return 1;
  }
  return 0;
}

int insertNode(Node **Root, int data)
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));

  // Inserted node is always a leaf
  // Only its parent changes;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  if(temp == NULL)
  {
      return -1;
  }

  if(isTreeEmpty(Root))
  {
      temp->parent = NULL;
      *Root = temp;
      return 1;
  }

  Node *ptr = *Root, *parent = *Root;
  int left = 0;
  while(ptr != NULL)
  {
      parent = ptr;
      if(data < ptr->data)
      {
          ptr = ptr->left;
	  left = 1;
      }
      //if(data >= ptr->data)
      else
      {
          ptr = ptr->right;
	  left = 0;
      }
      if(ptr == NULL && left == 1)
      {
          parent->left = temp;
	  temp->parent = ptr;
      }
      else if(ptr == NULL && left == 0)
      {
          parent->right = temp;
	  temp->parent = ptr;
      }
  }

  return 1;
}

int levelOrder(Node **Root)
{
  QNode *Head;
  initQueue(&Head);

  if(isTreeEmpty(Root))
  {
      return 0;
  }

  enqueue(&Head, *Root);
  //printf("Enqueued %d\n", (*Root)->data);
  Node *temp;

  while(!isEmpty(&Head))
  {
      //printQueue(&Head);
      temp = Head->data;

      printf("%d, ", temp->data);
      //printf(">: %d\n", temp->data);
      //printf("Dequeued %d\n", Head->data->data);
      dequeue(&Head);
      if(temp->left != NULL)
      {
          enqueue(&Head, temp->left);
	  //printf("Enqueued %d\n", temp->left->data);
      }
      if(temp->right != NULL)
      {
          enqueue(&Head, temp->right);
	  //printf("Enqueued %d\n", temp->right->data);
      }
  }
  printf("\n");

  return 1;
}

int inOrder(Node **Root)
{
  SNode *stack;

  initStack(&stack);

  if(isTreeEmpty(Root))
  {
      return 0;
  }

  Node *ptr = *Root;
  Node *temp;

  while(1)
  {
      if(ptr != NULL)
      {
          push(&stack, ptr);
	  ptr = ptr->left;
      }
      else
      {
          if(isStackEmpty(&stack))
	  {
	      printf("\n");
	      return 1;
	  }
	  else
	  {
	      temp = pop(&stack);
	      printf("%d, ", temp->data);
	      ptr = temp->right;
	  }
      }
  }
}

int preOrder(Node **Root)
{
  SNode *stack;

  initStack(&stack);

  if(isTreeEmpty(Root))
  {
      return 0;
  }

  Node *ptr = *Root;
  Node *temp;

  while(1)
  {
      if(ptr != NULL)
      {
          printf("%d, ", ptr->data);
	  push(&stack, ptr);
	  ptr = ptr->left;
      }
      else
      {
          if(isStackEmpty(&stack))
	  {
	      printf("\n");;
	      return 1;
	  }
	  else
	  {
	      temp = pop(&stack);
	      ptr = temp->right;
	  }
      }
  }
}

int postOrder(Node **Root)
{
  SNode *stack1, *stack2;

  initStack(&stack1);
  initStack(&stack2);

  if(isTreeEmpty(Root))
  {
      return 0;
  }

  Node *ptr = *Root;
  push(&stack1, ptr);
  Node *temp;

  while(!isStackEmpty(&stack1))
  {
      temp = pop(&stack1);
      push(&stack2, temp);

      if(temp->left != NULL)
      {
          push(&stack1, temp->left);
      }
      if(temp->right != NULL)
      {
          push(&stack1, temp->right);
      }
  }
  while(!isStackEmpty(&stack2))
  {
      printf("%d, ", pop(&stack2)->data);
  }
  printf("\n");
  return 1;
}

/*
int deleteNode(Node **Root, int data)
{
  Node* keyNode;
  keyNode = search(Root, data);
  if(temp == NULL)
  {
      return 0;
  }

  int typeOfNode = NodeType(keyNode);

  // Leaf Node
  if(typeOfNode == 3)
  {
      keyNode = NULL;
      free(keyNode);
      return 1;
  }

  // Has a left sub-tree but no right
  // take ptr to the right most of left sub-tree
  if(typeOfNode == 1)
  {
      Node *ptr = keyNode->left;
      while(ptr->right != NULL)
      {
          ptr = ptr->right;
      }


  }

  // Has a right child but no left
  if(typeOfNode == 2)
  {
      keyNode->parent->right = NULL;
      free(keyNode);
  }

  // Node has both the children
  // Take ptr to the left most element
  // in the right sub tree of the key
  ptr = keyNode->right;
  while(ptr->left != NULL)
  {
      ptr = ptr->left;
  }

  // Swapping Elements
  *(keyNode->data) = *(ptr->data);

  // Delete ptr
  ptr->parent->left = NULL;
  free(ptr);
  return 1;
}
*/
Node* search(Node **Root, int data)
{
  if(isTreeEmpty(Root))
  {
      printf("Tree is empty\n");;
      return NULL;
  }

  Node *ptr = *Root;
  while(1)
  {
      if(ptr == NULL)
      {
          //printf("Not found\n");
          return NULL;
      }
      if(ptr->data == data)
      {
          //printf("%d = %d, Found\n", ptr->data, data);
	  return ptr;
      }
      else if(ptr->data < data)
      {
          //printf("%d < %d, going right.\n", ptr->data, data);
	  ptr = ptr->right;
      }
      else
      {
          //printf("%d >= %d, going left.\n", ptr->data, data);
          ptr = ptr->left;
      }
  }
}

int NodeType(Node **node)
{
  if(*node == NULL)
  {
      return 0;
  }
  else if((*node)->left == NULL && (*node)->right != NULL)
  {
      return 1; // No right Node
  }
  else if((*node)->right == NULL && (*node)->left != NULL)
  {
      return 2; // No left Node
  }
  else if((*node)->left == NULL && (*node)->right == NULL)
  {
      return 3; // Leaf Node
  }
}
