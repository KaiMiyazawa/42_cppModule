# cpp Module 01
Lesson about C++ Memory Allocation, Pointers to members, References.
C++のメモリ割り当て、メンバへのポインタ、参照についての学びました。

## ex00 BraiiiiiiinnnzzzZ
This is a program that creates a zombie.
ゾンビを作成するプログラムです。
It's about memory allocation in C++.
C++のメモリ割り当てについてです。

### Usage
make and execute.
makeして実行します。
```shell
make
./Zombie
```

### What I learned
I learned about memory allocation in C++.
C++のメモリ割り当てについて学びました。

In C++, when you allocate dynamic memory, you use the `new` operator. When you delete it, you use the `delete` operator.
C++で動的メモリ割り当てを行う時は、`new`演算子。削除する時は、`delete`演算子を使います。

When you use member functions of a class, you write `CLASS.METHOD()`.
When you use member functions of a class pointer, you write `CLASS->METHOD()`.
クラスのメンバ関数にアクセスするときは`CLASS.METHOD()`と書く。
クラスのポインタのメンバ関数にアクセスするときは`CLASS->METHOD()`と書く。


## ex01 Moar brainz!
This is a program that creates a zombie array.
ゾンビの配列を作成するプログラムです。
It's about memory allocation in C++.
C++のメモリ割り当てについてです。

### Usage
make and execute.
makeして実行します。
```shell
make
./Zombie
```

### What I learned
I learned about memory allocation in C++ (especially arrays).
C++のメモリ割り当てについて学びました（特に配列）。

In C++, when you allocate dynamic memory for an array, you use the `new[]` operator. When you delete it, you use the `delete[]` operator.
C++で配列の動的メモリ割り当てを行う時は、`new[]`演算子。削除する時は、`delete[]`演算子を使います。

## ex02 HI THIS IS BRAIN
This is a program about brain.
脳についてのプログラムです。
It's about C++ pointers and references.
C++のポインタと参照についてです。

### Usage
make and execute.
makeして実行します。
```shell
make
./Brain
```

### What I learned
How to use pointers and references in C++.
C++でポインタと参照を使う方法を学びました。

## ex03 Unnecessary violence
This is a program about people having waepons.
武器を持つ人々についてのプログラムです。
It's about C++ pointers to members.
C++のメンバへのポインタについてです。

### Usage
make and execute.
makeして実行します。
```shell
make
./War
```

### What I learned
I learned about pointers and references to members in C++.
クラスのメンバ変数における、参照とポインタの違いについて学びました。

Pointers can be assigned NULL.
References cannot.
ポインタはNULLを代入できる。
参照はできない。

Pointers can use NULL to indicate "nothing".
On the other hand, if "nothing" is not possible, it is desirable to use references.
ポインタは"ない"ことを示すためにNULLを使える。
一方、"ない"ことがありえない場合は参照を使うと望ましい。

## ex04 Sed is for losers
This is a program about file input/output. It replaces a string in a file.
ファイルの入出力についてのプログラムです。ファイル内の文字列を置換します。

### Usage
make and execute.
makeして実行します。
```shell
make
./replace "filename" "s1" "s2"
```

### What I learned
I learned about file input/output in C++.
C++でのファイル入出力について学びました。
Used `std::string::find()`.
`std::string::find()`を使いました。

## ex05 Harl 2.0
This is a program reading stdin. When your input matches a specific string, it outputs a specific string.
標準入力を読み込むプログラムです。入力が特定の文字列と一致すると、特定の文字列を出力します。

### Usage
make and execute.
makeして実行します。
```shell
make
./Harl
```

### What I learned
I learned about avoiding if-else forest.
if-elseのネストを避ける方法を学びました。
I used function references array.
関数参照の配列を使いました。

That's all.
以上です。