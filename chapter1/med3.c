#include <stdio.h>

int med3(int a, int b, int c);

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

  printf("中央値は : %d", med3(a, b, c));

  return (0);
}

int max3(int a, int b, int c) {
  int max;
  max = a;

  if (max < b)
    max = b;
  if (max < c)
    max = c;

  return max;
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

int med3(int a, int b, int c) {
  return a + b + c - max3(a,b,c) - min3(a,b,c);
}
