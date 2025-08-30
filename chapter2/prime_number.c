/* 素数を求めるプログラム　総当たり*/
#include <stdio.h>

int main(void) {

  int n;
  int counter = 0;
  do {
    printf("入力した数値までの素数を表示します。\n "
           "2以上の数値を入力してください :");
    scanf("%d", &n);
  } while (n < 2);

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= i; j++) {
      if (i != j) {
        counter++;
        if (i % j == 0) {
          break;
        }
      }
      if (j == i) {
        printf("%-5d ", i);
      }
    }
  }
  printf("\n");
  printf("除算を行った回数 : %d", counter);
  return 0;
}
