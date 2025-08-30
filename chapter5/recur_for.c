/* 再帰の除去 2*/

#include <stdio.h>
#include <wchar.h>

// void recur(int n) {
//   if (n > 0) {
//     recur(n - 1);
//     printf("%d\n", n);
//     recur(n - 2);
//   }
// }
//

void recur(int n) {

  int stk[100];
  int ptr = 0;

  while (n > 0) {
    stk[ptr++] = n - 1;
    n = n - 1;

    if (ptr > 0) {
      n = stk[--ptr];
      printf("%d\n", n);
      n = n - 2;
    }
  }
  printf("%d\n", n);
}

int main(void) {
  int x;

  printf("整数を入力せよ\n");
  scanf("%d", &x);

  recur(x);

  return 0;
}
