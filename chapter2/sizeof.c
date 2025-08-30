#include <stdio.h>

int main(void) {
  int i;
  int a[5] = {1, 2, 3, 4, 5};
  int na = sizeof(a) / sizeof(a[0]);

  printf("配列aの要素数は%dです。\n", na);
  printf("sizeof(a) : %ld \n", sizeof(a));
  printf("sizeof(a[0] : %ld \n", sizeof(a[0]));

  for (i = 0; i < na; i++) {
    printf("a[%d] = %d\n", i, a[i]);
  }

  return 0;
}

/*
* 配列の要素数とsizeof演算子について
* sizeof()は関数に見えるけど、一応演算子
* ()内のもののバイト数を数えるようにできている。
* 今回のケースだとsizeof(a)はint型の配列５要素分なので、intは4byteのため20biteになる。
* sizeof(a[0])は１要素の大きさがわかる(今回はintのため4byte)ので、配列全体を１要素ごとで割れば
* 配列の要素数が出てくるという仕組みになっている。
*/ 


