#include <stdio.h>

int factorial(int n) {
  if (n < 1) {
    return 1;
  } else {
    int num = n * factorial(n - 1);
    printf("%d\n", num);
    return num;
  }
}

int main(void) {

  int n;
  printf("整数を入力せよ\n");
  scanf("%d", &n);

  printf("%dの階乗は%dです。", n, factorial(n));
}
