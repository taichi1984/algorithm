#include <stdio.h>

// void countdown(int n) {
//   if (n > 0) {
//     printf("%d\n", n);
//     countdown(n - 1);
//   }
// }
// 上記の処理をstack版で書き換える。
//

void countdown(int n) {
  // int stk[100];
  // int ptr = 0;

  while (n >= 0) {
    if (n >= 0) {
      printf("%d\n", n);
      n = n - 1;
    }
  }
}

int main(void) {
  int n;
  printf("自然数を入力 : ");
  scanf("%d", &n);

  countdown(n);
  return 0;
}
