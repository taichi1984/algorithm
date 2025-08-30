#include <stdio.h>
#include <stdlib.h>

void *binsearch(const void *key, const void *base, size_t nmemb, size_t size,
                int (*compar)(const void *, const void *)) {

  int top = 0;
  int bottom = nmemb - 1;
  int center;
  do {
    center = (top + bottom) / 2;
    if (compar((char *)base + center * size, key) == 0) {
      return (void *)((char *)base + center * size);
    } else if (compar((char *)base + center * size, key) <
               0) { // keyのほうが大きい
      top = center + 1;
    } else { // keyのほうが小さい
      bottom = center - 1;
    }
  } while (top <= bottom);

  return NULL;
}

int int_cmp(const void *a, const void *b) {
  int va = *(int *)a;
  int vb = *(int *)b;
  if (va < vb)
    return (-1);
  else if (va > vb)
    return (1);
  else
    return (0);
}
int main(void) {
  int i, ky, *p;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を昇順に入力してください。\n", nx);

  printf("x[0] : ");
  scanf("%d", &x[0]);

  for (i = 1; i < nx; i++) {
    do {
      printf("x[%d] : ", i);
      scanf("%d", &x[i]);
    } while (x[i] < x[i - 1]);
  }

  printf("探す値 : ");
  scanf("%d", &ky);

  p = binsearch(&ky, x, nx, sizeof(int), int_cmp);

  if (p == NULL)
    puts("探索に失敗しました\n");
  else
    printf("%dはx[%ld]にあります。\n", ky, ((int *)p - x));

  return (0);
}
