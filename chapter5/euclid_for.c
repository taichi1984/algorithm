#include <stdio.h>
int euclid_by_for(int n, int m) {

  while (m != 0) {
    int reminder;
    reminder = n % m;
    n = m;
    m = reminder;
  }

  return n;
}

int main(void) {

  int n, m;
  int max, min;

  printf("２つの自然数n,mの最大公約数を求めます。\n");
  printf("整数n:");
  scanf("%d", &n);

  printf("整数m:");
  scanf("%d", &m);

  if (n >= m) {
    max = n;
    min = m;
  } else {
    max = m;
    min = n;
  }

  int gcd = euclid_by_for(max, min);

  printf("最大公約数は%dです。\n", gcd);
}
