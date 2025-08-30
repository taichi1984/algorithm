/* 再帰の除去*/

#include <stdio.h>

void recur(int n) {
  int stk[100];
  int ptr = 0;
Top:
  if (n > 0) {
    stk[ptr++] = n;
    n = n - 1;
    goto Top;
  }
  if (ptr > 0) {
    n = stk[--ptr];
    printf("%d\n", n);
    n = n - 2;
    goto Top;
  }
}

int main(void) {
  int x;

  printf("整数を入力せよ\n");
  scanf("%d", &x);

  recur(x);

  return 0;
}
