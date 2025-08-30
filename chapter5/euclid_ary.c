#include <stdio.h>
#include <stdlib.h>

int euclid(int n, int m) {
  if (m != 0)
    return euclid(m, n % m);
  else
    return n;
}
int cmp_desc(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int gcdary(int a[], int n) {
  qsort(a, n, sizeof(int), cmp_desc);

  printf("qsort完了 : ");
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      printf("%d \n", a[i]);
    else
      printf("%d , ", a[i]);
  }

  int gcd = a[0];
  for (int i = 1; i < n; i++) {
    printf("gcd : %d \n", gcd);
    gcd = euclid(gcd, a[i]);
  }

  return gcd;
}

int main(void) {

  int array_length;
  do {
    printf("配列の要素数を決めてください : ");
    scanf("%d", &array_length);
  } while (array_length <= 0);

  int array[array_length];
  printf("配列に格納する値を入力してください。\n");

  for (int i = 0; i < array_length; i++) {

    printf("array[%d] :", i);
    scanf("%d", &array[i]);
  }

  int gcd;

  gcd = gcdary(array, array_length);

  for (int i = 0; i < array_length; i++) {
    if (i == array_length - 1)
      printf("%d", array[i]);
    else
      printf("%d ,", array[i]);
  }

  printf("の最大公約数は\n");
  printf("%d", gcd);
}
