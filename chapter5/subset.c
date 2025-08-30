#include <stdio.h>

void subset(int i, int n, int sel[]) {
  if (i == n) {
    // 出力
    for (int k = 0; k < n; k++)
      printf("%d", sel[k]);
    putchar('\n');
    return;
  }

  // 分岐: 選ぶ or 選ばない
  sel[i] = 0; // 限定操作: この要素を「選ばない」
  subset(i + 1, n, sel);

  sel[i] = 1; // 限定操作: この要素を「選ぶ」
  subset(i + 1, n, sel);
}

int main(void) {
  int a[3];
  subset(0, 2, a);
}
