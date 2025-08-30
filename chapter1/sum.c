#include <stdio.h>

int main(void) {
  int n;
  int sum = 0;

  int i;

  printf("１からいくつまでの総和を求める？:");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    sum += i;
  }

  printf("総和は : %d", sum);
}
