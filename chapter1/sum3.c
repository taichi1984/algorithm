#include <stdatomic.h>
#include <stdio.h>

int sumof(int a, int b);

int main(void) {
  int a, b;
  int sum;

  printf("１つ目の数？:");
  scanf("%d", &a);

  printf("１つ目の数？:");
  scanf("%d", &b);

  sum = sumof(a, b);

  printf("総和は : %d", sum);
}

int sumof(int a, int b) {
  int sum = 0;
  int min, max;
  int i = 0;

  if (a <= b) {
    min = a;
    max = b;
  } else {
    min = b;
    max = a;
  }

  for (i = min; i <= max; i++) {
    sum += i;
  }

  return sum;
}
