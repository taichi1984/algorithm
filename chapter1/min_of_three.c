#include <stdio.h>

int min3(int a, int b, int c);

int main(void) {
  int a;
  int b;
  int c;

  printf("aの値 : ");
  scanf("%d", &a);

  printf("bの値 : ");
  scanf("%d", &b);

  printf("cの値 : ");
  scanf("%d", &c);

  printf("最小値は : %d", min3(a, b, c));

  return (0);
}

int min3(int a, int b, int c) {
  int min;
  min = a;

  if (min > b)
    min = b;
  if (min > c)
    min = c;

  return min;
}


