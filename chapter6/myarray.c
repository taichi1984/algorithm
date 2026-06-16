#include "myarray.h"
#include <stdio.h>
#include <stdlib.h>

void random_array(int *array, int len)
/*
 *  int型の配列のポインタと長さを渡すと、ランダムな値を配列に格納する。
 *  あらかじめsrand(time(NULL))などでseedの設定はしておく必要がある。
 */
{
  for (int i = 0; i < len; i++) {
    array[i] = rand() % 20;
  }
}

void print_array(int *array, int len) {

  for (int i = 0; i < len; i++) {
    if (i == len - 1)
      printf("%2d", array[i]);
    else
      printf("%2d ", array[i]);
  }

  printf("\n");
}
