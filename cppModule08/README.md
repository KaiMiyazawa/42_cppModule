# cpp Module 08

**製作者**: kmiyazawa

## 概要
このモジュールはC++のテンプレートコンテナ、イテレータ、アルゴリズムについて学習するためのプロジェクトです。STL（Standard Template Library）の基本概念、アルゴリズム、イテレータパターン、カスタムコンテナの設計など、現代C++の重要な機能を実践的に習得します。

## 学習目標
- STLコンテナの理解と使用方法
- イテレータパターンの実装と活用
- STLアルゴリズムの使用方法
- カスタムコンテナクラスの設計
- 標準コンテナの拡張方法
- アルゴリズムとデータ構造の分離

## Exercise 00: Easy find

### 概要
テンプレート関数easyfindを実装し、STLコンテナから特定の値を検索する機能を学習します。

### 学翕内容
- STLアルゴリズム`std::find`の使用
- イテレータの基本概念
- テンプレートとSTLの組み合わせ
- 例外処理とエラーハンドリング

### 使用されるC++機能
- `std::find`アルゴリズム
- イテレータ（`iterator`）
- STLコンテナ（`vector`、`list`、`deque`など）
- テンプレート特化
- 例外処理

### easyfind関数の仕様
```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::exception();  // またはカスタム例外
    }
    return it;
}
```

### サポートするコンテナ
- `std::vector<int>`
- `std::list<int>`
- `std::deque<int>`
- その他のSTLシーケンシャルコンテナ

### コンパイル・実行方法
```bash
cd ex00
make
./easyfind
```

### 重要なポイント
- **イテレータパターン**: 統一されたアクセス方法
- **アルゴリズムの再利用**: コンテナとアルゴリズムの分離
- **例外処理**: 検索失敗時の適切な対応
- **テンプレート特化**: 特定の型に対する特別な処理

## Exercise 01: Span

### 概要
Spanクラスを実装し、数値の集合を管理し、最短距離や最長距離を計算する機能を学習します。

### 学習内容
- カスタムコンテナクラスの設計
- STLアルゴリズムの活用（`sort`、`min_element`、`max_element`）
- 大量データの効率的な処理
- イテレータ範囲を使った一括操作

### 使用されるC++機能
- `std::vector`コンテナ
- `std::sort`、`std::adjacent_find`、`std::min_element`、`std::max_element`
- イテレータ範囲
- 例外クラスの設計
- コンテナの容量管理

### Spanクラスの仕様
```cpp
class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
    
public:
    Span(unsigned int n);
    Span(const Span& other);
    ~Span();
    
    Span& operator=(const Span& other);
    
    void addNumber(int number);
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    // 例外クラス
    class SpanFullException : public std::exception {
        const char* what() const throw();
    };
    
    class SpanTooSmallException : public std::exception {
        const char* what() const throw();
    };
};
```

### 実装される機能
- **addNumber()**: 個別の数値を追加
- **addNumbers()**: イテレータ範囲で一括追加
- **shortestSpan()**: 最短距離の計算
- **longestSpan()**: 最長距離の計算
- **例外処理**: 容量オーバー、データ不足の処理

### コンパイル・実行方法
```bash
cd ex01
make
./span
```

### 重要なポイント
- **効率的なアルゴリズム**: ソートと近接要素検索の組み合わせ
- **イテレータ範囲**: 一括操作でのパフォーマンス向上
- **例外設計**: 適切なエラー処理とユーザーエクスペリエンス
- **STL活用**: 標準ライブラリの効果的な使用

### 未実装機能と改善点
> [!WARNING]
> **addNumbersメソッドの未実装**: イテレータ範囲での一括追加機能が未実装（-10点）

## Exercise 02: Mutanted abomination

### 概要
MutantStackクラスを実装し、標準のstackコンテナにイテレータ機能を追加します。

### 学習内容
- 標準コンテナの拡張方法
- イテレータの実装と公開
- コンテナアダプタの理解
- STLコンテナの内部構造

### 使用されるC++機能
- `std::stack`コンテナアダプタ
- テンプレート継承
- typedefでの型エイリアス
- イテレータのexpose
- コンテナアダプタの内部アクセス

### MutantStackクラスの仕様
```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();
    
    MutantStack& operator=(const MutantStack& other);
    
    // イテレータ型の定義
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    
    // イテレータアクセス関数
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};
```

### 実装の特徴
- **継承ベース**: `std::stack`をpublic継承
- **イテレータサポート**: 内部コンテナのイテレータを公開
- **STL互換**: STLアルゴリズムで使用可能
- **標準準拠**: 標準コンテナのインターフェースを保持

### コンパイル・実行方法
```bash
cd ex02
make
./mutantstack
```

### 重要なポイント
- **コンテナアダプタ**: 標準コンテナをラップした特化コンテナ
- **内部アクセス**: protectedメンバへのアクセス方法
- **型安全性**: テンプレートによる統一的なインターフェース
- **STL統合**: 標準ライブラリとのシームレスな統合

### 未実装機能と改善点
> [!WARNING]
> **テストケースの不足**: より包括的なテストケースが必要（-10点）

## 全体の学習成果
このモジュールを通じて以下の重要な概念を習得しました：

### STLの基本概念
- コンテナ、イテレータ、アルゴリズムの分離
- ジェネリックプログラミングの実践
- イテレータパターンの理解と実装

### コンテナ設計
- カスタムコンテナの設計原則
- 標準コンテナの拡張方法
- コンテナアダプタの活用

### アルゴリズムと最適化
- STLアルゴリズムの効果的な使用
- パフォーマンスを考慮したデータ処理
- 大量データの効率的な操作

### エラーハンドリング
- STLコンテキストでの例外設計
- 境界条件とエッジケースの処理
- ユーザーフレンドリーなエラーメッセージ

## 注意点
- **パフォーマンス**: STLアルゴリズムの計算量を理解して使用
- **メモリ管理**: コンテナの自動メモリ管理を活用
- **イテレータ無効化**: コンテナの変更時のイテレータ無効化に注意
- **型安全性**: テンプレートでの型制約とエラー検出
- **STL规範**: STLのコーディングスタイルとコンベンションに従う