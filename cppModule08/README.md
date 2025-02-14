# cpp Module 08
This module is about Templated containers, iterators, algorithms in C++.
このモジュールはC++のテンプレートコンテナ、イテレータ、アルゴリズムについてです。

## ex00 Easy find
This is a function `easyfind` that takes a container and a value, and returns an iterator to the first occurrence of the value in the container.
コンテナと値を取り、その値が最初に現れるコンテナ内のイテレータを返す`easyfind`関数です。

### Usage
```shell
make
./easyfind
```

### What I learned
I learned about Templated containers, iterators, algorithms (especially `find`) in C++.
C++のテンプレートコンテナ、イテレータ、アルゴリズム(特に`find`)について学びました。

## ex01 Span
This is a class `Span` that is a template class that holds a container of a given type, and has a method `addNumber` that adds a number to the container, and a method `shortestSpan` that returns the difference between the smallest two numbers in the container, and a method `longestSpan` that returns the difference between the largest and smallest numbers in the container.
与えられた型のコンテナを保持するテンプレートクラスである`Span`クラスです。コンテナに数値を追加する`addNumber`メソッドと、コンテナ内の最小の二つの数値の差を返す`shortestSpan`メソッド、コンテナ内の最大と最小の数値の差を返す`longestSpan`メソッドを持ちます。

### Usage
```shell
make
./span
```

### What I learned
I learned about Templated containers, iterators, algorithms (especially `sort`) in C++.
C++のテンプレートコンテナ、イテレータ、アルゴリズム(特に`sort`)について学びました.

## ex02 Mutanted abomination
This is a class `MutantStack` that is a template class that is a stack that inherits from `std::stack` and has iterators.
`std::stack`を継承し、イテレータを持つスタックであるテンプレートクラスである`MutantStack`クラスです。

### Usage
```shell
make
./mutantStack
```

### What I learned
I learned about Templated containers (especially `std::stack`), iterators, algorithms in C++.
C++のテンプレートコンテナ(特に`std::stack`)、イテレータ、アルゴリズムについて学びました。

That's all.
以上です。