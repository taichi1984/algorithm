#include <stdio.h>

void move(int no, char start, char aux, char target) {
  if (no > 1)
    move(no - 1, start, target, aux);

  printf("[%d]を%c軸から%c軸へ移動\n", no, start, target);

  if (no > 1)
    move(no - 1, aux, start, target);
}

int main(void) {
  int n;

  printf("円盤の枚数 : ");
  scanf("%d", &n);

  move(n, 'a', 'b', 'c');

  return (0);
}
