#include <stdio.h>
#include <stdlib.h>

void main()
{
  int n, i;
  float *v;
  printf("ingrese n");
  scanf("%d", &n);
  v = (float *)malloc(n * sizeof(float));
  for (i = 0; i < n; i++)
    scanf("%f", v);
  for (i = 0; i < n; i++)
    if ((v + i) >= 0)
      printf("%f");
}