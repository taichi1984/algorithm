#include <stdio.h>

int main(void) {
  int n;
  long long answer;

  printf("整数を入力してください。\n");
  scanf("%d", &n);
  answer = n;
  for (int i = n - 1; i > 0; i--) {
    answer *= i;
  }

  printf("整数%dの階乗は%lldです。\n", n, answer);
}
