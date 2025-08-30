/* 2~36進数まで対応する基数変換プログラム */

#include <stdio.h>

int main(void) {

  int base;
  int n;
  char answer[255];

  do {
    printf("元の数字: ");
    scanf("%d", &n);
  } while (n < 1); //元の数値が1以下なら再入力を促す。

  do {
    printf("何進数に変換する?:");
    scanf("%d", &base);
  } while (base < 2 || base > 36); // baseが2以下なら再入力を促す。

  const char *number = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int idx = 0;

  /* 基数変換の処理をし、答えを１桁ずつ逆からanswer文字列に代入*/
  while (n >= base) {
    answer[idx++] = number[n % base];
    n = n / base;
  }

  answer[idx] = number[n];
  idx++;
  answer[idx] = '\0';

  /* 基数変換の計算をした逆順の文字列をひっくり返す。*/
  int num_of_char = 0;

  while (answer[num_of_char] != '\0') {
    num_of_char++;
  }
  for (int i = 0; i < num_of_char / 2; i++) {
    char tmp = answer[i];
    answer[i] = answer[num_of_char - i - 1];
    answer[num_of_char - i - 1] = tmp;
  }

  printf("%s \n", answer);
}
