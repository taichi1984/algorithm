/* 素数を求めるプログラム　総当たり
 * 割る数、割られる数を基数を除外の他、n / 2
 * 以上の数で割る場合は必ず余りが出るため、そのケースも除外している。*/
#include <stdio.h>

int main(void) {

  int n;
  int counter = 0;
  do {
    printf("入力した数値までの素数を表示します。\n "
           "2以上の数値を入力してください :");
    scanf("%d", &n);
  } while (n < 2);

  printf("%-5d ", 2);

  /* 割られる数、割る数ともに偶数は計算する必要なし*/

  for (int i = 3; i <= n; i += 2) {
    int is_prime = 1;
    for (int j = 3; j <= i / 2; j += 2) {
      counter++;
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime)
      printf("%-5d ", i);
  }
  printf("\n");
  printf("除算を行った回数 : %d", counter);
  return 0;
}
