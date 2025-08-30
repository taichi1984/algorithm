#include <stdio.h>

int gcd(int a, int b) {

  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main(void) {
  int n, m;
  printf("2つの自然数 n　と m について、最大公約数を求めます。\n");
  printf("nを入力 :");
  scanf("%d", &n);

  printf("mを入力 :");
  scanf("%d", &m);

  if (n >= m)
    printf("最大公約数は%dです。\n", gcd(n, m));
  else
    printf("最大公約数は%dです。\n", gcd(m, n));
}
