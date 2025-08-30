/* 二分探索 -- ソートされたデータから効率よく値を探索する*/

#include <stdio.h>
#include <stdlib.h>

/* 要素n個の配列a[]からkeyと一致する要素を2分探索する */

int long_cmp(const void *a, const void *b) {

  long va = *(const long *)a;
  long vb = *(const long *)b;

  if (va < vb)
    return 1;
  else if (va > vb)
    return -1;
  else
    return 0;
}

int main(void) {
  long i, ky, *p;
  long x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を降順に入力してください。\n", nx);

  printf("x[0] : ");
  scanf("%ld", &x[0]);

  for (i = 1; i < nx; i++) {
    do {
      printf("x[%d] : ", i);
      scanf("%ld", &x[i]);
    } while (x[i] > x[i - 1]);
  }

  printf("探す値 : ");
  scanf("%ld", &ky);

  p = bsearch(&ky, x, nx, sizeof(long),
              (int (*)(const void *, const void *))long_cmp);

  if (p == NULL)
    puts("探索に失敗しました\n");
  else
    printf("%ldは%ld番目にあります。\n", ky, p - x + 1);

  return (0);
}
