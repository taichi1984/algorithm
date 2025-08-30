/* 素数を求めるプログラム　総当たり
 * エラトステネスの篩で実行する。*/

#include <stdio.h>

int main(void) {

  long n;
  int counter = 0;

  do {
    printf("入力した数値までの素数を表示します。\n "
           "2以上の数値を入力してください :");
    scanf("%ld", &n);
  } while (n < 2);

  char is_prime[n + 1];

  /* フラグ配列を全てtrueで初期化*/

  for (int i = 0; i <= n; i++)
    is_prime[i] = 't';

  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i] == 'f') {
      printf("%d が fのため飛ばす\n", i);
      continue;
    }

    if (is_prime[i] == 't') {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = 'f';
        counter++;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (is_prime[i] == 't')
      printf("%-5d  ", i);
  }

  printf("\n");
  printf("除算を行った回数 : %d\n", counter);
  return 0;
}

/**
 *  基本アイデア
 *  - 素数の倍数をどんどん消していけば、残った数が素数になる。
 *  ー小さい素数から順に「その倍数を消す」ということを繰り返すだけ
 *
 * 内側ループの工夫
 *
 *
 *
 *
 */
