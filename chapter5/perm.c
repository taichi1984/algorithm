#include <stdio.h>

int used[100];
int ans[100];

void perm(int depth, int n, int used[], int ans[]) {
  if (depth == n) {
    for (int i = 0; i < n; i++)
      printf("%d ", ans[i]);
    putchar('\n');
    return;
  }

  for (int j = 0; j < n; j++) {
    if (!used[j]) {   // 既に使った要素はスキップ（枝刈り）
      ans[depth] = j; // この位置に j を置く
      used[j] = 1;    // フラグ立てる
      perm(depth + 1, n, used, ans);
      used[j] = 0; // 戻ってきたらフラグを戻す（バックトラッキング）
    }
  }
}

int main(void) { perm(0, 3, used, ans); }
