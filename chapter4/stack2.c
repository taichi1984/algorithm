#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

/* スタックを実現する構造体 */
typedef struct {
  int max;
  int ptr_h;
  int ptr_l;
  int *stk;
} Stack;

/* --- スタックの初期化 --- */

int StackAlloc(Stack *s, int max) {
  s->ptr_h = 0;
  s->ptr_l = max - 1;
  if ((s->stk = calloc(max, sizeof(int))) == NULL) {
    s->max = 0;
    return (-1);
  }

  s->max = max;
  return (0);
}

/* ---スタックの後始末 ---*/
void StackFree(Stack *s) {
  if (s->stk != NULL) {
    free(s->stk);
    s->max = s->ptr_h = 0;
  }
}

/* ---スタック_hにデータをpush */

int StackPush_h(Stack *s, int x) {

  if (s->ptr_h > s->ptr_l) {
    return -1;
  }

  s->stk[s->ptr_h++] = x;
  return (0);
}
/* ---スタック_lにデータをpush */

int StackPush_l(Stack *s, int x) {

  if (s->ptr_l < s->ptr_h) {
    return -1;
  }

  s->stk[s->ptr_l--] = x;
  return (0);
}

/* ---スタック_hからデータをポップ --- */
int StackPop_h(Stack *s, int *x) {
  if (s->ptr_h <= 0)
    return -1;
  *x = s->stk[--s->ptr_h];
  return (0);
}

/* ---スタック_lからデータをポップ --- */
int StackPop_l(Stack *s, int *x) {
  if (s->ptr_l == s->max - 1)
    return -1;
  *x = s->stk[++s->ptr_l];
  return (0);
}

/*---スタックからデータをピーク ---*/

int StackPeek_h(const Stack *s, int *x) {
  if (s->ptr_h <= 0)
    return -1;
  *x = s->stk[s->ptr_h - 1];
  return (0);
}

/* スタック_lからデータをピーク */
int StackPeek_l(const Stack *s, int *x) {
  if (s->ptr_l == s->max - 1)
    return -1;
  *x = s->stk[s->ptr_l + 1];
  return (0);
}
/* スタックの大きさ */

int StackSize(const Stack *s) { return s->max; }

/* スタックに積まれているデータ数 */

int StackNo_h(const Stack *s) { return (s->ptr_h); }

int StackNo_l(const Stack *s) { return ((s->max - 1) - s->ptr_l); }

/* スタックは空か? */

int StackIsEmpty_h(const Stack *s) { return s->ptr_h <= 0; }

int StackIsEmpty_l(const Stack *s) { return s->ptr_l == s->max - 1; }

/* スタックは満杯か */

int StackIsFull_h(const Stack *s) { return s->ptr_h > s->ptr_l; }

int StackIsFull_l(const Stack *s) { return s->ptr_h > s->ptr_l; }

/* スタックを空にする */

void StackClear_h(Stack *s) { s->ptr_h = 0; }

void StackClear_l(Stack *s) { s->ptr_l = s->max - 1; }
int main(void) {
  Stack s;

  if (StackAlloc(&s, 5) == -1) {
    puts("スタックの確保に失敗しました。\n");
    return (1);
  }

  while (1) {
    int m, x;
    printf("現在のデータ数 : h , %d : l , %d , size : %d \n", StackNo_h(&s),
           StackNo_l(&s), StackSize(&s));
    printf("(1)Hにプッシュ (2)Hからポップ (3) lにプッシュ (4) lからポップ (0) "
           "終了 : ");
    scanf("%d", &m);

    if (m == 0)
      break;

    switch (m) {
    case 1:
      printf("データ:");
      scanf("%d", &x);
      if (StackPush_h(&s, x) == -1) {
        puts("hスタックへのプッシュに失敗しました。");
      }
      break;
    case 2:
      if (StackPop_h(&s, &x) == -1) {
        puts("ポップできません。\n");
      } else {
        printf("hからポップしたデータは%dです。\n", x);
      }
      break;
    case 3:
      printf("データ:");
      scanf("%d", &x);
      if (StackPush_l(&s, x) == -1) {
        puts("lスタックへのプッシュに失敗しました。");
      }
      break;
    case 4:
      if (StackPop_l(&s, &x) == -1) {
        puts("ポップできません。\n");
      } else {
        printf("lからポップしたデータは%dです。\n", x);
      }
      break;
    }
  }
  StackFree(&s);

  return (0);
}
