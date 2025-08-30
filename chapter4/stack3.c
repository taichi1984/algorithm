#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

/* スタックを実現する構造体 */
typedef struct {
  size_t sz; //要素の大きさ
  int max;   //最大の要素数
  int ptr;
  void *stk;
} Stack;

/* --- スタックの初期化 --- */

Stack *StackAlloc(int max, size_t sz) {
  Stack *s = malloc(sizeof(Stack));
  if (!s)
    return NULL;

  if ((s->stk = calloc(max, sz)) == NULL) {
    s->max = 0;
    free(s);
    return NULL;
  }
  s->max = max;
  s->sz = sz;
  s->ptr = 0;
  return s;
}

/* ---スタックの後始末 ---*/
void StackFree(Stack *s) {
  if (s) {
    free(s->stk);
    free(s);
  }
}

/* ---スタックにデータをpush */

int StackPush(Stack *s, void *x) {

  if (s->ptr >= s->max) {
    printf("不正なプッシュ\n");
    return 0;
  }
  memcpy((char *)s->stk + s->ptr * s->sz, x, s->sz);
  s->ptr++;
  return 1;
}

/* ---スタックからデータをポップ --- */
int StackPop(Stack *s, void *x) {
  if (s->ptr <= 0)
    return 0;
  s->ptr--;
  memcpy(x, (char *)s->stk + s->ptr * s->sz, s->sz);

  return 1;
}

/*---スタックからデータをピーク ---*/
int StackPeek(const Stack *s, void *x) {
  if (s->ptr <= 0)
    return 0;
  memcpy(x, (char *)s->stk + (s->ptr - 1) * s->sz, s->sz);
  return 1;
}

/* スタックの大きさ */

int StackSize(const Stack *s) { return s->max; }

/* スタックに積まれているデータ数 */

int StackNo(const Stack *s) { return (s->ptr); }

/* スタックは空か? */

int StackIsEmpty(const Stack *s) { return s->ptr <= 0; }

/* スタックは満杯か */

int StackIsFull(const Stack *s) { return s->ptr >= s->max; }

/* スタックを空にする */

void StackClear(Stack *s) { s->ptr = 0; }

int main(void) {
  Stack *s;

  if ((s = StackAlloc(100, sizeof(double))) == NULL) {
    puts("スタックの確保に失敗しました。\n");
    return (1);
  }

  while (1) {
    int m;
    double x;
    printf("現在のデータ数 : %d : %d\n", StackNo(s), StackSize(s));
    printf("(1)プッシュ (2) ポップ (0) 終了 : ");
    scanf("%d", &m);

    if (m == 0)
      break;

    switch (m) {
    case 1:
      printf("データ:");
      scanf("%lf", &x);
      if (StackPush(s, &x) == 0) {
        puts("スタックへのプッシュに失敗しました。");
      }
      break;
    case 2:
      if (StackPop(s, &x) == 0) {
        puts("ポップできません。\n");
      } else {
        printf("ポップしたデータは%lfです。\n", x);
      }
      break;
    }
  }
  StackFree(s);

  return (0);
}
