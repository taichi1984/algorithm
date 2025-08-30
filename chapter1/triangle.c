#include <stdio.h>

void trilb(int n);
void trilu(int n);
void triru(int n);
void trirb(int n);

int main(void) {
  int i, j, n;

  printf("左下が直角\n\n");
  printf("何段の三角形ですか? : ");
  scanf("%d", &n);

  trilb(n);

  printf("左上が直角\n\n");

  trilu(n);

  printf("右上が直角\n\n");

  triru(n);
  printf("右下が直角\n\n");

  trirb(n);
  return (0);
}

/* 左下が直角 */

void trilb(int n) {
  int i, j;

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {

      printf("*");
    }
    printf("\n");
  }
}

/* 左上が直角 */
void trilu(int n) {
  int i, j;

  for (i = n; i >= 1; i--) {
    for (j = i; j >= 1; j--) {
      printf("*");
    }
    printf("\n");
  }
}

/* 右上が直角 */
void triru(int n) {
  int i, j;

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (j <= i) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

/* 右下が直角 */
void trirb(int n) {
  int i, j;

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (n - i < j) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
