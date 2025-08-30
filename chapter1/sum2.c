#include <stdio.h>

int main(void) {
  int n;
  int sum = 0;

  int i;
  char sumprint[10000];
  printf("１からいくつまでの総和を求める？:");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    sum += i;

    if (i < n)
      printf("%d + ", i);

    if (i == n)
      printf("%d = ", i);
  }

  printf("%d", sum);
}
