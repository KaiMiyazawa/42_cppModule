// main.cpp
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

// ヘルパー関数：すでにソート済みのコンテナ A に対し、val を二分探索により挿入する
template <typename Container>
void binaryInsert(Container & A, const typename Container::value_type & val) {
    typedef typename Container::iterator Iterator;
    Iterator it = std::lower_bound(A.begin(), A.end(), val);
    A.insert(it, val);
}

// Ford–Johnson アルゴリズム（Merge–insertion sort）
// 対象コンテナは std::vector や std::deque などランダムアクセス可能なものを想定する．
// コンテナの要素型は operator< による大小比較が可能であることが前提です．
template <typename Container>
void fordJohnsonSort(Container & A) {
    typedef typename Container::size_type Size;
    typedef typename Container::value_type T;

    // 要素数が 0 または 1 なら何もする必要はない
    if (A.size() <= 1)
        return;

    // 【特別処理：奇数個の場合】
    // Ford–Johnson アルゴリズムはまず偶数個の要素に対してペア分けを行うのが基本であるため，
    // 要素数が奇数の場合は，末尾の要素（extra）を一時的に取り除き，
    // 残り（偶数個）に対してアルゴリズムを実行し，最後に binaryInsert により挿入する．
    if (A.size() % 2 == 1) {
        T extra = A.back();
        A.pop_back();
        fordJohnsonSort(A);
        binaryInsert(A, extra);
        return;
    }

    // 【ここから：偶数個の場合】
    Size n = A.size();

    // --- 1. ペア分けと比較 ---
    // 入力 A の要素を 2 個ずつペアに分け，各ペアで大きいほう（winner）と小さいほう（loser）を決定する．
    // ※ ただし，最初のペアは特殊扱いとなり，その loser は後の挿入順序のために別変数に保持する．

    // pending（未挿入要素）として，ペアで出た loser を保持する．
    // ここでは，loser と，そのペアであった winner（これを threshold として後で参照する）を保持する．
    struct PendingPair {
        T loser;
        T threshold; // この loser は，対応する threshold より必ず小さい（threshold はペアで大きかった値）
        PendingPair(const T & th, const T & l)
            : loser(l), threshold(th) {}
    };

    // winners は，ペアから得た大きいほうの値を集めたもの．
    // 後に再帰的にソートし，さらに特殊な挿入操作を施す．
    Container winners;
    // （reserve() 呼び出しは vector では可能だが，deque ではないので push_back だけで実装）

    std::vector<PendingPair> pending; // ペアで得た loser（ただし最初のペアの loserは pending には入れない）

    // 【特殊ペア】
    // A[0] と A[1] を比較し，大きいほうを winners に，
    // 小さいほうは specialLoser として別に保持する（後で winners の先頭に挿入する）
    T specialLoser;
    if (A[0] < A[1]) {
        winners.push_back(A[1]);
        specialLoser = A[0];
    } else {
        winners.push_back(A[0]);
        specialLoser = A[1];
    }

    // 【残りのペア】
    // 2 番目以降のペアについては，
    // ・大きいほう（winner）は winners に push_back し，
    // ・小さいほう（loser）は pending に，そのペアでの winner（threshold として）とともに記録する．
    for (Size i = 1; i < n / 2; ++i) {
        Size idx0 = 2 * i;
        Size idx1 = 2 * i + 1;
        if (A[idx0] < A[idx1]) {
            winners.push_back(A[idx1]);
            pending.push_back(PendingPair(A[idx1], A[idx0]));
        } else {
            winners.push_back(A[idx0]);
            pending.push_back(PendingPair(A[idx0], A[idx1]));
        }
    }
    // ここで，winners のサイズは n/2 （特殊ペアから 1 個，それ以降のペアから n/2 - 1 個）
    // pending のサイズは n/2 - 1 である．

    // --- 2. 再帰的ソート ---
    // winners 内の要素は，後で正しい全体順序を構成するための「骨格」となる．
    // この winners に対して同じアルゴリズムを再帰的に適用してソートする．
    fordJohnsonSort(winners);

    // --- 3. 特殊挿入 ---
    // 最初のペアで得た specialLoser を，winners の先頭に挿入する．
    // これにより，winners 内は最初の 2 要素がペアになったことになり，
    // 残り pending の各要素は，winners の 3 番目以降の要素に対応するものとなる．
    winners.insert(winners.begin(), specialLoser);
    // この時点で winners のサイズは (n/2 + 1) となる．

    // --- 4. 未挿入要素（pending）のグループ分けと挿入順序の決定 ---
    // pending に記録された loser（未挿入要素）は，文献で説明されるように，
    // まず「グループ分け」され，
    // 各グループ内では「大きい番号から先に挿入」される．
    //
    // Wikipedia などの説明では，グループサイズは以下の系列になる：
    //    2, 2, 6, 10, 22, 42, … 
    // ここでは，この系列をハードコードして pending の挿入順序（インデックス順）を作成する．
    //
    // pending 内の要素は，もともと y₃, y₄, y₅, … と番号付けされているとみなす．
    // （特殊ペアの loserは番号付け対象外となる）
    Size P = pending.size();
    std::vector<Size> insertionOrder; // pending 内のインデックス（0～P-1）の並び順
    // ハードコードされたグループサイズ系列
    const int groupSizes[] = {2, 2, 6, 10, 22, 42, 86, 170};
    const int numGroupSizes = sizeof(groupSizes) / sizeof(groupSizes[0]);
    Size processed = 0;
    for (int g = 0; g < numGroupSizes && processed < P; ++g) {
        int currentGroup = groupSizes[g];
        // 実際に確保できるグループサイズは，残り P - processed と比較して小さい方
        int actualGroupSize = (processed + currentGroup <= P) ? currentGroup : (P - processed);
        // 同グループ内では，後ろ（番号が大きいもの）から挿入するので，
        // グループ内のインデックスを逆順に order に追加する．
        for (int j = 0; j < actualGroupSize; ++j) {
            insertionOrder.push_back(processed + actualGroupSize - 1 - j);
        }
        processed += currentGroup;
    }
    // もし insertionOrder のサイズが P に満たなければ，
    // 残りは単純に逆順（大きい番号から）とする．
    if (insertionOrder.size() < P) {
        for (Size i = P; i > insertionOrder.size(); --i)
            insertionOrder.push_back(i - 1);
    }
    if (insertionOrder.size() > P)
        insertionOrder.resize(P);

    // --- 5. pending 内の各要素の挿入 ---
    // insertionOrder で示された順番に pending 内の各 loser を winners に挿入する．
    // 挿入の際，各 pending 要素 p は，
    // 「p.threshold」（＝元のペアで大きかった方）より前の部分列（winners の先頭～ p.threshold の位置まで）
    // に対して二分探索を行い，適切な位置に p.loser を挿入する．
    for (Size k = 0; k < insertionOrder.size(); ++k) {
        Size idx = insertionOrder[k];
        if (idx >= pending.size())
            continue; // 安全のため
        const PendingPair & p = pending[idx];
        // winners 内から，p.threshold の「最初の出現位置」を探す（winners はソート済み）
        typename Container::iterator it = std::lower_bound(winners.begin(), winners.end(), p.threshold);
        // 探索範囲は winners.begin() ～ it（p.threshold 未満の部分）．
        // その範囲内で，p.loser を挿入すべき位置を上側探索（upper_bound）で求める．
        typename Container::iterator pos = std::upper_bound(winners.begin(), it, p.loser);
        winners.insert(pos, p.loser);
    }

    // --- 6. 結果を元のコンテナ A に戻す ---
    // winners が最終的なソート済み列となる．
    A = winners;
}

int main() {
    // 例1: std::vector<int> の場合
    std::vector<int> vec;
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(2);
    // 要素数が偶数ならそのまま，奇数の場合は上記実装内で処理する．

    fordJohnsonSort(vec);

    std::cout << "Sorted vector: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // 例2: std::deque<int> の場合
    std::deque<int> deq;
    deq.push_back(10);
    deq.push_back(7);
    deq.push_back(15);
    deq.push_back(2);
    deq.push_back(9);
    deq.push_back(4);
    deq.push_back(6);  // 奇数個の場合
    fordJohnsonSort(deq);

    std::cout << "Sorted deque: ";
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << std::endl;

    return 0;
}
