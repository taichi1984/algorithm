#include "myarray.h"
#include "mysort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 10

int main() {

  srand(time(NULL));
  int array[ARRAY_SIZE];
  random_array(array, ARRAY_SIZE);
  printf("ソート前配列 \n");
  print_array(array, ARRAY_SIZE);
  printf("\n");
  bubble_sort(array, ARRAY_SIZE, ORDER_ASC, 1);
  printf("\n ソート後配列 \n");
  print_array(array, ARRAY_SIZE);

}
