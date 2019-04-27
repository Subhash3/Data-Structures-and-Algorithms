#include <stdio.h>
#include <stdlib.h>

Nice
{
  int a;
  int b;
};

int main()
{
  Nice *n;

  n->a = 1;
  n->b = 2;

  printf("%d, %d\n", n->a, n->b);

  exit(0);
}
