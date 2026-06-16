#include "mysort.h"
#include <stdio.h>
#define SORT_VERBOSE 1
static void swap_int(int *x, int *y);

int bubble_sort(int *array, int len, sort_order order, int option)
/*
 *  int型の配列
 */
{

  int compare_num = 0;
  int swapnum = 0;
  if (order != ORDER_ASC && order != ORDER_DESC) {
    fprintf(stderr, "orderにはORDER_ASCかORDER_DESCを指定してください\n");
    return -1;
  }

  int k = 0;

  while (k < len - 1) {
    int j;
    int last = len - 1;

    for (j = len - 1; j > k; j--) {
      // 交換の詳細表示処理
      if (option == SORT_VERBOSE) {
        for (int l = 0; l < len; l++) {
          printf("%2d ", array[l]);
          if (l == j - 1) {
            if (order == ORDER_ASC) {
              if (array[j - 1] < array[j]) {
                printf("+ ");
              } else {
                printf("- ");
              }
            } else if (order == ORDER_DESC) {
              if (array[j - 1] > array[j]) {
                printf("+ ");
              } else {
                printf("- ");
              }
            }
          } else {
            printf("  ");
          }
        }
        printf("\n");
      }

      // 実際の交換処理
      compare_num++;
      if (order == ORDER_ASC) {
        if (array[j - 1] > array[j]) {
          swap_int(&array[j - 1], &array[j]);
          last = j;
          swapnum++;
        }
      } else if (order == ORDER_DESC) {
        if (array[j - 1] < array[j]) {
          swap_int(&array[j - 1], &array[j]);
          last = j;
          swapnum++;
        }
      }
    }
    k = last;
  }

  /* 以下は初期バージョン*/
  // for (int j = 0; j < len - 1; j++) {
  //   int exchg = 0;
  //   for (int i = 0; i < len - 1 - j; i++) {
  //     // 交換の詳細を表示するロジック
  //     if (option == SORT_VERBOSE) {
  //       for (int k = 0; k < len; k++) {
  //         printf("%2d ", array[k]);
  //         if (k == i) {
  //           if (order == ORDER_ASC) {
  //             if (array[i] > array[i + 1]) {
  //               printf("+ ");
  //             } else {
  //               printf("- ");
  //             }
  //           } else if (order == ORDER_DESC) {
  //             if (array[i] < array[i + 1]) {
  //               printf("+ ");
  //             } else {
  //               printf("- ");
  //             }
  //           }
  //         } else {
  //           printf("  ");
  //         }
  //       }
  //       printf("\n");
  //     }
  //     // 実際の交換のロジック
  //     if (order == ORDER_ASC) {
  //       if (array[i] > array[i + 1]) {
  //         swap_int(&array[i], &array[i + 1]);
  //         swapnum++;
  //         exchg++;
  //       }
  //     } else if (order == ORDER_DESC) {
  //
  //       if (array[i] < array[i + 1]) {
  //         swap_int(&array[i], &array[i + 1]);
  //         swapnum++;
  //         exchg++;
  //       }
  //     }
  //     compare_num++;
  //   }
  //   if (exchg == 0) {
  //     break;
  //   }
  // }
  //
  //

  if (option == SORT_VERBOSE) {
    printf("\n");
    printf("比較回数 :  %d 回 \n", compare_num);
    printf("交換回数 : %d 回 \n", swapnum);
    printf("\n");
  }
  return 0;
}

static void swap_int(int *x, int *y) {
  int buf;
  buf = *x;
  *x = *y;
  *y = buf;
}
