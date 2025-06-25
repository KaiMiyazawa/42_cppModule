# cpp Module 05

**製作者**: kmiyazawa

## 概要
このモジュールはC++の例外処理（Exception Handling）について学習するためのプロジェクトです。try-catch文、例外クラスの設計、例外安全性などの重要な概念を、Bureaucrat（官僚）とForm（書類）のシステムを実装しながら実践的に習得します。

## 学習目標
- 例外処理の基本概念と実装方法
- try-catch-throw文の使用方法
- カスタム例外クラスの設計
- 例外安全性の理解
- RAII（Resource Acquisition Is Initialization）の実践
- ファクトリーパターンの実装

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

### 概要
Bureaucratクラスを実装し、C++の例外処理の基本を学習します。

### 学習内容
- 例外クラスの設計と実装
- try-catch文の基本的な使用
- 境界値チェックと例外の投げ方
- 例外安全なコンストラクタの実装

### 使用されるC++機能
- `throw`文
- `try-catch`文
- カスタム例外クラス
- `std::exception`の継承
- `const`メンバ関数

### Bureaucratクラスの仕様
- **属性**:
  - `name`: 官僚の名前（const、変更不可）
  - `grade`: 官僚の等級（1-150、1が最高位）

- **メンバ関数**:
  - `getName()`: 名前を取得
  - `getGrade()`: 等級を取得
  - `incrementGrade()`: 等級を上げる
  - `decrementGrade()`: 等級を下げる

- **例外クラス**:
  - `GradeTooHighException`: 等級が高すぎる（1未満）
  - `GradeTooLowException`: 等級が低すぎる（150超過）

### コンパイル・実行方法
```bash
cd ex00
make
./bureaucrat
```

### 重要なポイント
- **等級の範囲**: 1（最高）から150（最低）まで
- **例外の継承**: `std::exception`を基底クラスとする
- **const正確性**: 名前は変更不可、適切なconst修飾
- **例外安全性**: コンストラクタでの範囲チェック

## Exercise 01: Form up, maggots!

### 概要
Formクラスを追加し、Bureaucratとの相互作用を通じて例外処理の応用を学習します。

### 学習内容
- 複数クラス間での例外処理
- 署名と実行の権限管理
- booleanフラグを使った状態管理
- 複雑な条件下での例外処理

### 使用されるC++機能
- クラス間の相互作用
- bool型の状態管理
- 複数の例外クラス
- friend関数（オプション）

### Formクラスの仕様
- **属性**:
  - `name`: 書類の名前（const）
  - `isSigned`: 署名済みフラグ（bool）
  - `gradeToSign`: 署名に必要な等級（const）
  - `gradeToExecute`: 実行に必要な等級（const）

- **メンバ関数**:
  - `beSigned()`: Bureaucratによる署名処理
  - `getters`: 各属性の取得関数

- **例外クラス**:
  - `GradeTooHighException`
  - `GradeTooLowException`

### Bureaucratクラス（拡張）
- **追加メンバ関数**:
  - `signForm()`: 書類に署名を試行

### コンパイル・実行方法
```bash
cd ex01
make
./forms
```

### 重要なポイント
- **権限チェック**: 署名前の等級確認
- **状態管理**: 署名済みフラグの適切な管理
- **例外処理**: 失敗時の適切な例外投げ
- **相互作用**: Bureaucrat-Form間の連携

## Exercise 02: No, you need form 28B, not 28C...

### 概要
抽象クラスAFormを実装し、具体的な書類クラス（ShrubberyCreationForm、RobotomyRequestForm、PresidentialPardonForm）を作成します。

### 学習内容
- 抽象クラスの設計と実装
- 純粋仮想関数の活用
- 具象クラスでの具体的な実装
- ファイル操作と例外処理

### 使用されるC++機能
- 抽象クラス（純粋仮想関数）
- ファイルストリーム
- 継承による機能の拡張
- テンプレートメソッドパターン

### AFormクラス（抽象クラス）
- **純粋仮想関数**: `execute()`
- **共通機能**: 署名処理、基本的な検証

### 具象書類クラス
#### ShrubberyCreationForm
- **目的**: ASCII樹木をファイルに出力
- **必要等級**: 署名145、実行137
- **実行内容**: `<target>_shrubbery`ファイルの作成

#### RobotomyRequestForm
- **目的**: ロボトミー手術の実行
- **必要等級**: 署名72、実行45
- **実行内容**: 50%の確率で成功メッセージ

#### PresidentialPardonForm
- **目的**: 大統領による恩赦
- **必要等級**: 署名25、実行5
- **実行内容**: 恩赦メッセージの表示

### コンパイル・実行方法
```bash
cd ex02
make
./forms
```

### 重要なポイント
- **抽象化**: 共通処理の抽象クラス化
- **具体化**: 各書類の固有処理実装
- **ファイル操作**: 例外安全なファイル書き込み
- **確率処理**: ランダムな結果の実装

## Exercise 03: At least this beats coffee-making

### 概要
Internクラスを実装し、ファクトリーパターンによる動的な書類生成を学習します。

### 学習内容
- ファクトリーパターンの実装
- 関数ポインタまたは関数オブジェクトの使用
- 文字列による動的オブジェクト生成
- エラーハンドリングの高度な技法

### 使用されるC++機能
- 関数ポインタの配列
- 文字列比較による分岐
- 動的オブジェクト生成
- エレガントなエラーハンドリング

### Internクラスの仕様
- **メンバ関数**:
  - `makeForm()`: 書類名に基づいて適切な書類を生成

- **サポートする書類**:
  - "shrubbery creation"
  - "robotomy request"
  - "presidential pardon"

### 実装アプローチ
```cpp
class Intern {
private:
    AForm* makeShrubberyCreationForm(const std::string& target);
    AForm* makeRobotomyRequestForm(const std::string& target);
    AForm* makePresidentialPardonForm(const std::string& target);
    
public:
    AForm* makeForm(const std::string& formName, const std::string& target);
};
```

### コンパイル・実行方法
```bash
cd ex03
make
./intern
```

### 重要なポイント
- **ファクトリーパターン**: オブジェクト生成の抽象化
- **関数ポインタ**: if-else文の代替実装
- **エラーハンドリング**: 未知の書類名への対応
- **メモリ管理**: 動的に生成されたオブジェクトの責任

## 全体の学習成果
このモジュールを通じて以下の重要な概念を習得しました：

### 例外処理の基本
- try-catch-throw文の適切な使用
- カスタム例外クラスの設計
- 例外安全性の重要性

### 設計パターンの実装
- ファクトリーパターンによるオブジェクト生成
- テンプレートメソッドパターンの活用
- 抽象クラスによるインターフェース設計

### 高度なC++機能
- 純粋仮想関数と抽象クラス
- 関数ポインタの実践的使用
- RAII原則の適用

### システム設計の考慮事項
- クラス間の責任分担
- エラー処理の一貫性
- 拡張性のある設計

## 注意点
- **例外安全性**: リソースリークを防ぐための適切な例外処理
- **const正確性**: 変更されるべきでないデータの保護
- **メモリ管理**: 動的に生成されたオブジェクトの適切な削除
- **境界値チェック**: 入力値の妥当性検証
- **例外の粒度**: 適切なレベルでの例外クラス設計