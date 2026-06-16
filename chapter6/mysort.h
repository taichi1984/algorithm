#ifndef MYSORT_H
#define MYSORT_H
typedef enum{
  ORDER_ASC,
  ORDER_DESC
} sort_order;

int bubble_sort(int *array, int len , sort_order order , int option);

#endif
