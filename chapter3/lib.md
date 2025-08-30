# この章で出てきた標準ライブラリ

## bsearch()関数

ソート済み配列に対する二分探索を行う

### ヘッダ
```
#include<stdlib.h>
```

### 書式
```
#include<stdlib.h>

void *search(const void *key , const void *base,size_t nitems, size_t size , int (*compar)(const void *, const void*));
```

### 引数
key : 探したい値へのポインタ
base : 探索対象の配列の先頭ポインタ
nitems : 配列の要素数
size  :  1要素の大きさ
(*compar)(const void *, const void*) : 比較関数;

### 戻り値
一致する要素が見つかった場合 : その要素へのポインタ
見つからない場合 : NULL
複数一致する場合 : どの要素が返るかは未定義





