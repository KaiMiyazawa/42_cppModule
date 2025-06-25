# cpp Module 06

**製作者**: kmiyazawa

## 概要
このモジュールはC++のキャスト（型変換）について学習するためのプロジェクトです。C++の4つの主要なキャスト演算子（static_cast、dynamic_cast、const_cast、reinterpret_cast）の使い方と、型変換、シリアライゼーション、型識別などの重要な概念を実践的に習得します。

## 学習目標
- C++の4つのキャスト演算子の理解と使い分け
- スカラー型間の安全な型変換
- シリアライゼーションとデシリアライゼーション
- 実行時型情報（RTTI）の活用
- 型安全性の重要性
- ポインタと参照の型識別技法

## Exercise 00: Conversion of scalar types

### 概要
ScalarConverterクラスを実装し、文字列から各種スカラー型（char、int、float、double）への変換を行います。

### 学習内容
- 文字列解析と型変換
- 変換可能性の判定
- エラーハンドリングと例外処理
- 特殊値（nan、inf）の処理
- 表示可能文字の判定

### 使用されるC++機能
- `static_cast`
- `std::strtod`、`std::strtof`
- `std::numeric_limits`
- `std::isprint`
- 文字列ストリーム処理

### ScalarConverterクラスの仕様
- **静的メンバ関数**: `convert(const std::string& literal)`
- **変換対象型**:
  - char: 文字表現
  - int: 整数表現
  - float: 単精度浮動小数点
  - double: 倍精度浮動小数点

### 変換ルール
- **char**: 表示可能文字のみ表示、それ以外は"Non displayable"
- **int**: オーバーフロー時は"impossible"
- **float**: 精度を保持して表示（.0f付き）
- **double**: 精度を保持して表示（.0付き）

### コンパイル・実行方法
```bash
cd ex00
make
./convert "42"
./convert "42.0f"
./convert "nan"
./convert "inf"
```

### 重要なポイント
- **型安全性**: 不正な変換の検出と処理
- **特殊値**: nan、inf、-infの適切な処理
- **精度保持**: 浮動小数点数の精度を保つ表示
- **境界値**: 各型の最大・最小値の考慮

## Exercise 01: Serialization

### 概要
Serializerクラスを実装し、ポインタのシリアライゼーション（uintptr_t型への変換）とデシリアライゼーション（ポインタへの復元）を学習します。

### 学習内容
- `reinterpret_cast`の使用方法
- ポインタとuintptr_t間の変換
- シリアライゼーションの基本概念
- 型安全性を犠牲にした低レベル変換

### 使用されるC++機能
- `reinterpret_cast`
- `uintptr_t`型
- 静的メンバ関数
- ポインタ演算

### Serializerクラスの仕様
```cpp
class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
```

### Dataクラス
```cpp
struct Data {
    int value;
    std::string name;
};
```

### コンパイル・実行方法
```bash
cd ex01
make
./serializer
```

### 重要なポイント
- **reinterpret_cast**: 最も危険なキャスト、型安全性なし
- **ポインタの一意性**: serialize→deserialize後の同一性保証
- **プラットフォーム依存**: uintptr_tのサイズ
- **用途の限定**: 低レベルプログラミングでのみ使用

## Exercise 02: Identify real type

### 概要
Base、A、B、Cクラスの継承階層を作成し、実行時型情報（RTTI）を使用して実際の型を識別する技法を学習します。

### 学習内容
- `dynamic_cast`の使用方法
- 実行時型情報（RTTI）の活用
- ポインタと参照での型識別の違い
- 多態性を活用した型判定

### 使用されるC++機能
- `dynamic_cast`
- 仮想関数による多態性
- try-catch文
- RTTI（Run-Time Type Information）

### クラス階層
```cpp
class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
```

### 実装される関数
- `Base* generate()`: ランダムにA、B、Cのいずれかを生成
- `void identify(Base* p)`: ポインタの実際の型を識別
- `void identify(Base& p)`: 参照の実際の型を識別

### 型識別手法
#### ポインタの場合
```cpp
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}
```

#### 参照の場合
```cpp
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::bad_cast&) {
            std::cout << "C" << std::endl;
        }
    }
}
```

### コンパイル・実行方法
```bash
cd ex02
make
./identify
```

### 重要なポイント
- **dynamic_cast**: 継承階層での安全な型変換
- **失敗時の動作**: ポインタはnullptr、参照は例外
- **仮想関数の必要性**: RTTIには仮想関数が必須
- **例外処理**: 参照でのdynamic_cast失敗時の対処

## 全体の学習成果
このモジュールを通じて以下の重要な概念を習得しました：

### C++キャストの理解
- **static_cast**: 基本的な型変換、コンパイル時チェック
- **dynamic_cast**: 継承階層での安全な変換、実行時チェック
- **const_cast**: const修飾の追加・削除
- **reinterpret_cast**: 低レベル型変換、型安全性なし

### 型安全性の重要性
- 適切なキャストの選択
- 型変換時のエラーハンドリング
- コンパイル時 vs 実行時チェック

### 実行時型情報（RTTI）
- dynamic_castによる型識別
- 仮想関数テーブルの活用
- ポインタと参照での処理の違い

### シリアライゼーション
- データの永続化・伝送の基本
- ポインタのバイナリ表現
- プラットフォーム依存性の考慮

## 注意点
- **キャストの選択**: 最も安全で適切なキャストを選択
- **reinterpret_cast**: 極力使用を避け、必要時のみ慎重に使用
- **RTTI**: パフォーマンスのオーバーヘッドを考慮
- **例外処理**: dynamic_castでの例外の適切な処理
- **型安全性**: C言語スタイルのキャストは避ける