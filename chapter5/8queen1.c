#include <stdio.h>

int pos[8]; //各列の王妃の配置
int flag[8];
int flag_b[15]; /* / 対角線上に王妃が配置済みか */
int flag_c[15]; /* \ 対角線上に王妃が配置済みか */

/*--- 盤面(各列の王妃の位置)を出力 ---*/

void print(void) {
  int i;

  for (i = 0; i < 8; i++)
    printf("%2d", pos[i]);
  putchar('\n');
}

/*--- i列目に王妃を配置 ---*/
void set(int i) {
  int j;

  for (j = 0; j < 8; j++) {
    if (!flag[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
      pos[i] = j;
      if (i == 7)
        print();
      else {
        flag[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
        set(i + 1);
        flag[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
      }
    }
  }
}

int main(void) {
  set(0);

  return (0);
}
