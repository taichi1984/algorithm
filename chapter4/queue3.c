/* リングバッファを用いたqueueの実装 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int size;
  int max;
  int num;
  int frontptr;
  int rearptr;
  void *que;
} Queue;

Queue *queueAlloc(int max, size_t size) {
  Queue *queue = malloc(sizeof(Queue));
  if (!queue)
    return NULL;

  queue->size = size;
  queue->max = max;
  queue->num = 0;
  queue->frontptr = 0;
  queue->rearptr = 0;
  queue->que = calloc(queue->max, queue->size);

  if (!queue->que) {
    free(queue);
    return NULL;
  }

  return queue;
}

int enqueue(Queue *queue, void *x) {

  if (queue->num >= queue->max) {
    printf("enqueue失敗\n");
    return -1;
  }

  queue->num++;
  memcpy((char *)queue->que + queue->size * queue->rearptr, x, queue->size);
  queue->rearptr++;

  if (queue->rearptr == queue->max)
    queue->rearptr = 0;
  return 1;
}

int dequeue(Queue *queue, void *x) {
  if (queue->num < 1) {
    printf("dequeue失敗\n");
    return -1;
  }

  queue->num--;
  memcpy(x, (char *)queue->que + queue->size * queue->frontptr, queue->size);
  queue->frontptr++;
  if (queue->frontptr == queue->max)
    queue->frontptr = 0;
  return 1;
}

int main(void) {

  Queue *queue;
  if ((queue = queueAlloc(5, sizeof(int))) == NULL) {
    printf("queueの作成に失敗しました。\n");
    return 1;
  }

  while (1) {
    int m, x;

    printf("(1) enqueue  (2) dequeue (0)Stop  :");
    scanf("%d", &m);

    if (m == 0)
      break;
    switch (m) {
    case 1:
      printf("データ:");
      scanf("%d", &x);
      if (enqueue(queue, &x) == -1)
        puts("エンキュー失敗\n");
      break;
    case 2:
      if (dequeue(queue, &x) == -1)
        puts("デキュー失敗\n");
      else
        printf("dequeueしたデータは%dです。\n", x);
      break;
    }
  }

  free(queue->que);
  free(queue);
}
