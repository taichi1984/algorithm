#include <stdio.h>
#include <wchar.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size,
                int (*compar)(const void *, const void *)) {

  for (int i = 0; i < nmemb; i++) {
    if (compar((const char *)base + i * size, key) == 0)
      return (void *)((const char *)base + i * size);
  }

  return NULL;
}

int int_cmp(const void *a, const void *b) {
  int va = *(const int *)a;
  int vb = *(const int *)b;
  if (va < vb)
    return -1;
  else if (vb > va)
    return 1;
  else
    return 0;
}

int main(void) {
  int key;
  int *p;
  int idx[7];
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);
  int num;
  printf("%d 個の整数を入力してください。\n", nx - 1);

  for (int i = 0; i < nx - 1; i++) {
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  printf("探す値 : ");
  scanf("%d", &key);

  p = seqsearch(&key, x, nx, sizeof(int), int_cmp);

  if (p == NULL)
    printf("探索失敗\n");
  else
    printf("%dの場所はx[%ld]です。\n", key, ((int *)p - x));

  return (0);
}
