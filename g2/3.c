#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *a, *b, *c;
  a = (int *)malloc(sizeof(int));
  b = (int *)malloc(sizeof(int));
  c = (int *)malloc(sizeof(int));
  printf("ingrese a b y c");
  scanf("%d %d %d", a, b, c);
  printf("la suma es %d", *a + b * +c *, "\n")
      printf("el producto es %d", (*a) * (*b) * (*c), "\n");
  free(a);
  free(b);
  free(c);
  return 0;
}
