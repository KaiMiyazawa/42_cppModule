# cpp Module 06
Lesson about C++ Casts.
C++のキャストについて学びました。

## ex00 Conversion of scalar types
This is a program that converts scalar types.
スカラー型を変換するプログラムです。

### Usage
```shell
make
./convert
```

### What I learned
I learned about C++ casts using `std::istringstream`.
`std::istringstream`を使ったC++のキャストについて学びました。

## ex01 Serialization
This is a program that serializes and deserializes.
シリアライズとデシリアライズを行うプログラムです。

### Usage
```shell
make
./serializer
```

### What I learned
I learned about serialization and deserialization in C++. I used `reinterpret_cast`.
C++でのシリアライズとデシリアライズについて学びました。`reinterpret_cast`を使いました。

## ex02 Identify real type
This is a program that identifies the real type of a pointer and a reference.
ポインタと参照の実際の型を特定するプログラムです。

### Usage
```shell
make
./identify
```

### What I learned
I learned about `dynamic_cast` in C++.
C++での`dynamic_cast`について学びました.
If you want to identify the real type of a pointer, you can use `dynamic_cast` with if-else statement.
If you want to identify the real type of a reference, you can use `dynamic_cast` with try-catch statement.
もしポインタの実際の型を特定したい場合は、`dynamic_cast`をif-else文と一緒に使います。
もし参照の実際の型を特定したい場合は、`dynamic_cast`をtry-catch文と一緒に使います。

That's all.
以上です。