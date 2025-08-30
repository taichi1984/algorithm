# 関数ポインタについて
## 関数ポインタとは？
通常のポインタは変数を参照するポインタ。
関数ポインタは関数を参照するポインタ。

## 関数はメモリ上に存在する。
Cでは、関数も「メモリに配列された命令列」
その関数の先頭アドレスをポインタで表現可能。
これが関数ポインタ。

## 関数ポインタの書き方
```
int add(int a , int b ) {
    return a + b;
}
```
という関数があったとしたら

```
int (*fp)(int, int)

```
と表せる。
引数int,int をとり、結果 int を返す関数fpです。
*fpの部分を()で囲うのが非常に重要で、この()がCの処理系が、これを関数ポインタだと判断する根拠になっている。
これ()で囲い忘れると全く別の意味になる(関数fpがint型のポインタを返す)ので注意。


## 使い方

```

fp = add;
int result = fp(2,3);
printf("%d\n",result);


```

関数ポインタを通しても、普通に関数を呼ぶのと同じように()を付けて呼び出せる。

## 関数ポインタを受けとった関数の実装例


```
int add(int a , int b ) {
    return a + b;
}

int sub(int a, int b ){
    return a - b;
}
```

上の二つの関数があったとする。
```
int calc_with_func(int x , int y, int(*op)(int,int)){
    return op(x,y);
}
```


このように引数として、関数を受け取り実行する仕組みを作れば、受け取った引数によって関数calc_with_funcを変えられる。

```
int main(void) {
    int a = 10, b = 3;

    printf("a + b = %d\n", calc_with_func(a, b, add));
    printf("a - b = %d\n", calc_with_func(a, b, sub));

    return 0;
}
```

実行結果

```
a + b = 13
a - b = 7
```

## 注意
Cだといつものことだが、関数ポインタの書き方が結構紛らわしいので間違えないように注意。

