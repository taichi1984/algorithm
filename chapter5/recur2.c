/* 再帰に対する理解を深めるための真に再帰的な関数*/

#include <stdio.h>

void recur2(int n) {
  if (n > 0) {
    recur2(n - 2);
    printf("%d\n", n);
    recur2(n - 1);
  }
}

int main(void) {
  int x;

  printf("整数を入力せよ\n");
  scanf("%d", &x);

  recur2(x);

  return 0;
}
