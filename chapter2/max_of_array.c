/* 配列の要素の最大値を求める。 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int array[10];
  int i;
  int max = 0;
  /* 乱数で配列の要素を決定していく */
  srand(time(NULL));
  for (i = 0; i < 10; i++) {
    array[i] = rand() % 15;
    printf("%d  ", array[i]);
  }
  printf("\n");

  for (i = 0; i < 10; i++) {
    if (max < array[i])
      max = array[i];
  }

  printf("配列内の最大値は %d", max);
  return 0;
}
