#include <stdio.h>
typedef struct {
  int no;
  int stage;
  int x;
  int y;
} state;

void move(int no, int x, int y) {
  state stk[100];
  int ptr = 0;

  stk[ptr++] = (state){no, 0, x, y};

TOP:

  if (no > 1) {
    stk[ptr++] = (state){no, 0, x, 6 - x - y};
    goto TOP;
  }

  if (ptr > 0) {
    no = stk[--ptr];
    printf("[%d]を%d軸から%d軸へ移動\n", no, x, y);
    if (no > 1) {
      no = no - 1;
      x = 6 - x - y;
      goto TOP;
    }
  }
}

int main(void) {
  int n;

  printf("円盤の枚数 : ");
  scanf("%d", &n);

  move(n, 1, 3);

  return (0);
}
