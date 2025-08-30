/* 配列の要素を逆順にする。 */
#define SIZE 13
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int array[SIZE];
  int i;
  int tmp;
  /* 乱数で配列の要素を決定していく */
  srand(time(NULL));
  for (i = 0; i < SIZE; i++) {
    array[i] = rand() % 15;
    printf("%2d  ", array[i]);
  }
  printf("\n");

  /* 配列の要素を逆順にする */
  for (i = 0; i < (SIZE / 2); i++) {
    tmp = array[i];
    array[i] = array[SIZE - 1 - i];
    array[SIZE - 1 - i] = tmp;
  }

  for (i = 0; i < SIZE; i++) {
    printf("%2d  ", array[i]);
  }
  printf("\n");
  return 0;
}

/*
 * 配列の前から順に配列の長さ/ 2
 * 回分、添え字iの要素と配列の最後の添え字-iの要素を入れ替えればよい。
 * 配列の要素数が偶数ならちょうど半分までやったところで全ての入れ替わりが終わる。
 * 配列の要素数が奇数なら一番真ん中の要素については、処理を行わないため、問題なく位置が入れ替わるようになっている。
 */
