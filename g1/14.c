#include <stdio.h>

int main()
{
  int n, i, j;
  printf("ingrese n");
  scanf("%d", n);
  for (i = 1, i <= n, i++)
    printf("#");
  printf("\n");
  for (i = 2, i <= n - 1, i++)
  {
    printf("#");
    for (j = 2, j <= n - 1, j++)
      printf(" ");
    printf("#\n");
  }
  for (i = 1, i <= n, i++)
    printf("#");

  scanf();
  return 0;
}