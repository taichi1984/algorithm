#include <stdio.h>

void spira(int n);
int main(void) {
  int n;

  do {
    printf("ピラミッドの段数を入力してください。:");
    scanf("%d", &n);
  } while (n < 1);

  spira(n);

  return 0;
}

void spira(int n) {

  int height = n;
  int base = (2 * n) - 1; // 表示領域の横幅

  int i, j; // 表示用2次元ディスクリプタ

  for (i = 1; i <= height; i++) {
    for (j = 1; j <= base; j++) {
      if (j >= (base / 2 + 1) - (i - 1) && j <= (base / 2 + 1) + (i - 1)) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
