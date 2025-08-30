/* リングバッファを用いたdequeの実装 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int max;
  int num;
  int frontptr;
  int rearptr;
  int *que;
} Queue;

Queue *queueAlloc(int max) {
  Queue *queue = malloc(sizeof(Queue));
  if (!queue)
    return NULL;

  queue->max = max;
  queue->num = 0;
  queue->frontptr = 0;
  queue->rearptr = 0;
  queue->que = calloc(queue->max, sizeof(int));

  if (!queue->que) {
    free(queue);
    return NULL;
  }

  return queue;
}

int enqueue_to_rear(Queue *queue, int x) {

  if (queue->num >= queue->max) {
    printf("enqueue失敗\n");
    return -1;
  }

  queue->num++;
  queue->que[queue->rearptr++] = x;
  if (queue->rearptr == queue->max)
    queue->rearptr = 0;
  return 1;
}

int dequeue_from_front(Queue *queue, int *x) {
  if (queue->num < 1) {
    printf("dequeue失敗\n");
    return -1;
  }

  queue->num--;
  *x = queue->que[queue->frontptr++];
  if (queue->frontptr == queue->max)
    queue->frontptr = 0;
  return 1;
}

int enqueue_to_front(Queue *queue, int x) {

  if (queue->num >= queue->max) {
    printf("enqueue失敗\n");
    return -1;
  }

  queue->num++;
  if (queue->frontptr == 0)
    queue->frontptr = queue->max - 1;
  else
    queue->frontptr--;
  queue->que[queue->frontptr] = x;

  return 1;
}

int dequeue_from_rear(Queue *queue, int *x) {
  if (queue->num < 1) {
    printf("dequeue失敗\n");
    return -1;
  }

  queue->num--;
  if (queue->rearptr == 0)
    queue->rearptr = queue->max - 1;
  else
    queue->rearptr--;
  *x = queue->que[queue->rearptr];
  return 1;
}

int main(void) {

  Queue *queue;
  if ((queue = queueAlloc(5)) == NULL) {
    printf("queueの作成に失敗しました。\n");
    return 1;
  }

  while (1) {

    for (int i = 0; i < queue->max; i++) {
      if (i == queue->max - 1)
        printf("%d\n", queue->que[i]);
      else
        printf("%d ,", queue->que[i]);
    }

    int m, x;
    printf("(1) enqueue to rear  (2) dequeue from front (3) enqueue to front "
           "(4) dequeue from rear (0)Stop  :");
    scanf("%d", &m);

    if (m == 0)
      break;
    switch (m) {
    case 1:
      printf("データ:");
      scanf("%d", &x);
      if (enqueue_to_rear(queue, x) == -1)
        puts("エンキュー失敗\n");
      break;
    case 2:
      if (dequeue_from_front(queue, &x) == -1)
        puts("デキュー失敗\n");
      else
        printf("dequeueしたデータは%dです。\n", x);
      break;
    case 3:
      printf("データ:");
      scanf("%d", &x);
      if (enqueue_to_front(queue, x) == -1)
        puts("エンキュー失敗\n");
      break;
    case 4:
      if (dequeue_from_rear(queue, &x) == -1)
        puts("デキュー失敗\n");
      else
        printf("dequeueしたデータは%dです。\n", x);
      break;
    }
  }

  free(queue->que);
  free(queue);
}
