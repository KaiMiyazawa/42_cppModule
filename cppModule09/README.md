# cpp Module 09

**製作者**: kmiyazawa

## 概要
このモジュールはC++の標準テンプレートライブラリ（STL）の高度な活用について学習するためのプロジェクトです。マップ、スタック、ベクター、デックなどのSTLコンテナを使用して、実用的なアプリケーションを構築し、パフォーマンス、アルゴリズム設計、データ処理などの重要な概念を実践的に習得します。

## 学習目標
- STLコンテナの実用的な活用方法
- 時系列データの管理と検索
- スタックを使った数式評価の実装
- 複数のコンテナでのパフォーマンス比較
- 高度なソーティングアルゴリズムの実装
- ファイル入出力とデータ解析

## Exercise 00: Bitcoin Exchange

### 概要
Bitcoinの時系列価格データを管理し、指定された日付での価格査詢と計算を行うプログラムを実装します。

### 学習内容
- `std::map`を使った時系列データの管理
- CSVファイルの解析とデータロード
- 日付のバリデーションと正規化
- 近接キー検索と補間処理
- 数値範囲のチェックとエラーハンドリング

### 使用されるC++機能
- `std::map<std::string, float>`
- ファイルストリーム（`std::ifstream`）
- 文字列処理と解析
- イテレータと検索アルゴリズム
- 例外処理とエラーレポーティング

### BitcoinExchangeクラスの仕様
```cpp
class BitcoinExchange {
private:
    std::map<std::string, float> _data;
    
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    BitcoinExchange& operator=(const BitcoinExchange& other);
    
    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
    float getExchangeRate(const std::string& date) const;
    
private:
    bool isValidDate(const std::string& date) const;
    bool isValidValue(float value) const;
    std::string findClosestDate(const std::string& date) const;
};
```

### ファイル形式
#### データベースファイル（data.csv）
```
date,exchange_rate
2009-01-02,0
2009-01-09,0
...
```

#### 入力ファイル（input.txt）
```
date | value
2011-01-03 | 3
2011-01-03 | 2
...
```

### コンパイル・実行方法
```bash
cd ex00
make
./btc input.txt
```

### 重要なポイント
- **連想コンテナ**: `std::map`のソート済み特性を活用
- **時系列検索**: `lower_bound`での効率的な近接検索
- **データバリデーション**: 日付形式と数値範囲の厳密なチェック
- **エラーハンドリング**: 細かいエラーメッセージと適切な処理

## Exercise 01: Reverse Polish Notation

### 概要
逆ポーランド記法（RPN）で記述された数式を評価する計算機を実装します。

### 学習内容
- `std::stack`を使った数式評価
- スタックベースのアルゴリズム設計
- 数字と演算子の解析と処理
- エラー検出と例外処理
- オーバーフローや除算ゼロの処理

### 使用されるC++機能
- `std::stack<int>`
- 文字列処理とトークン化
- 数値変換とバリデーション
- 例外処理とエラーレポーティング

### RPNクラスの仕様
```cpp
class RPN {
private:
    std::stack<int> _stack;
    
public:
    RPN();
    RPN(const RPN& other);
    ~RPN();
    
    RPN& operator=(const RPN& other);
    
    int calculate(const std::string& expression);
    
private:
    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    int performOperation(int a, int b, const std::string& op) const;
    std::vector<std::string> tokenize(const std::string& expression) const;
};
```

### サポートされる演算
- **算術演算**: `+`、`-`、`*`、`/`
- **オペランド**: 0から10未満の整数
- **数式形式**: スペース区切りのRPN記法

### RPN記法の例
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"  # (8*9-9-9-9-4+1) = 42
./RPN "7 7 * 7 -"                  # (7*7-7) = 42
./RPN "1 2 * 2 / 2 * 2 4 - +"     # ((1*2/2*2)+(2-4)) = 0
```

### コンパイル・実行方法
```bash
cd ex01
make
./RPN "3 4 + 2 * 7 /"
```

### 重要なポイント
- **スタック操作**: push/popの適切なタイミング
- **エラー検出**: 不正な式、除算ゼロ、オーバーフローの処理
- **アルゴリズム効率**: O(n)の線形時間計算量
- **スタック状態**: 最終的にスタックに1個の値が残ること

### 実装の注意点
> [!NOTE]
> **日付解析の実装**: `strptime()`を使用した実装の方がよりロバストであった可能性がありますが、提出版では文字列処理で実装しています。

## Exercise 02: PmergeMe

### 概要
Ford-Johnsonアルゴリズム（merge-insertion sort）を実装し、`std::vector`と`std::deque`のパフォーマンスを比較します。

### 学習内容
- 高度なソーティングアルゴリズムの実装
- 複数のコンテナでのパフォーマンス測定
- 時間計算量の最適化技法
- メモリアクセスパターンの違い
- 大量データの効率的な処理

### 使用されるC++機能
- `std::vector<int>`と`std::deque<int>`
- `std::chrono`での時間測定
- 再帰的アルゴリズムの実装
- イテレータとアルゴリズムの組み合わせ
- コマンドライン引数の処理

### PmergeMeクラスの仕様
```cpp
class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    
    PmergeMe& operator=(const PmergeMe& other);
    
    void parseInput(int argc, char* argv[]);
    void sortAndCompare();
    
private:
    template <typename Container>
    void mergeInsertionSort(Container& container);
    
    template <typename Container>
    double measureSortTime(Container& container);
    
    void displayResults() const;
    bool isValidNumber(const std::string& str) const;
};
```

### Ford-Johnsonアルゴリズムの特徴
- **理論的最適性**: 最少の比較回数でソート
- **ハイブリッドアプローチ**: マージと挑入ソートの組み合わせ
- **再帰構造**: 分割統治法の活用
- **最適化**: 小さなデータセットでの高速化

### コンパイル・実行方法
```bash
cd ex02
make
./PmergeMe 3 5 9 7 4
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```

### 出力例
```
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 us
Time to process a range of 5 elements with std::deque  : 0.00014 us
```

### 重要なポイント
- **アルゴリズム効率**: O(n log n)の最適性を目指す
- **コンテナ比較**: vector vs dequeのメモリ特性の違い
- **時間測定**: マイクロ秒単位での精密測定
- **スケーラビリティ**: 大量データでのパフォーマンス維持

## 全体の学習成果
このモジュールを通じて以下の重要な概念を習得しました：

### STLコンテナの高度な活用
- 各コンテナの特性と適切な使い分け
- パフォーマンス特性とメモリ使用量の理解
- アルゴリズムとコンテナの最適な組み合わせ

### 実用的なアプリケーション設計
- ファイル入出力とデータ処理
- エラーハンドリングとユーザーエクスペリエンス
- コマンドラインインターフェースの設計

### アルゴリズム設計と最適化
- 時間計算量と空間計算量のトレードオフ
- 実用的なパフォーマンス測定技法
- 高度なソーティングアルゴリズムの理解

### データ構造とアルゴリズムの統合
- 連想コンテナでの効率的な検索
- スタックベースの問題解決アプローチ
- 複数コンテナでの同一アルゴリズム実装

## 注意点
- **メモリ効率**: 大量データ処理時のメモリ使用量に注意
- **パフォーマンス測定**: 正確なベンチマークのための測定環境と方法
- **アルゴリズム選択**: データサイズと特性に適したアルゴリズム選択
- **エラー処理**: 不正な入力や例外状態の適切な処理
- **可読性**: 複雑なアルゴリズムの可読性と保守性のバランス