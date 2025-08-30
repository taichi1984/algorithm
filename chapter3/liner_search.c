#include <stdio.h>

/* ---- 要素数nの配列aからkeyと一致する要素を線形探索 ----*/
int search(int a[], int n, int key, int idx[]) {
  int i = 0;
  int num = 0;
  a[n - 1] = key;

  for (i = 0; i < n; i++) {

    if (a[i] == key) {
      idx[num] = i;
      num++;
    }
  }

  return num;
}

int main(void) {
  int i, ky;
  int idx[7];
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);
  int num;
  printf("%d 個の整数を入力してください。\n", nx - 1);
  for (i = 0; i < nx - 1; i++) {
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  printf("探す値 : ");
  scanf("%d", &ky);

  num = search(x, nx, ky, idx);

  return (0);
}
