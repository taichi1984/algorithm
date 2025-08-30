#include <stdio.h>

int main(void) {
  int digit, n;
  digit = 0;

  do {
    printf("任意の正の整数を入力してください。 : ");
    scanf("%d", &n);
  } while (n <= 0);

  while (n > 0) {
    n = n / 10;
    digit++;
  }

  printf("その数は%d桁です。\n", digit);
  return (0);
}
