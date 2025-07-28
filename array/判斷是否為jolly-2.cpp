#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>   // 為了 std::iota
#include <algorithm> // 為了 std::sort

using namespace std;

bool isJollyJumper_simple(const vector<int>& seq) {
    int n = seq.size();
    if (n <= 1) {
        return true;
    }

    // === 第一步：計算所有差值 ===
    vector<int> diffs;
    for (int i = 0; i < n - 1; ++i) {
        diffs.push_back(abs(seq[i] - seq[i + 1]));
    }

    // === 第二步：排序並檢查 ===
    // 1. 先對我們收集到的差值列表進行排序
    sort(diffs.begin(), diffs.end());

    // 2. 建立一個標準答案列表，也就是 [1, 2, 3, ..., n-1]
    vector<int> expected_diffs(n - 1);
    iota(expected_diffs.begin(), expected_diffs.end(), 1); // 這個函式能快速產生 1, 2, 3... 的序列

    // 3. 比較我們排序後的差值列表，是否和標準答案一模一樣
    return diffs == expected_diffs;
}

int main() {
    vector<int> seq = {1, 4, 2, 3};
    cout << "【簡單版】序列 {1, 4, 2, 3} 是 Jolly Jumper嗎? " 
         << (isJollyJumper_simple(seq) ? "是" : "否") << endl;
}



/* iota(expected_diffs.begin(), expected_diffs.end(), 1);
這是什麼意思？
你可以把 iota 想像成一個自動填數字的工人。你告訴他：

expected_diffs.begin(): 從容器 expected_diffs 的最開始位置動手。

expected_diffs.end(): 一直填到結束位置為止（不包含結束位置本身）。

1: 第一個數字請從 1 開始填。

它的工作流程
假設在呼叫這行程式碼之前，你的 expected_diffs 是一個大小為 3 的空殼向量（例如，內容是 {0, 0, 0}）。

iota 會這樣工作：

它拿起你給的起始值 1，填入 expected_diffs 的第 0 個位置。向量變成 {1, 0, 0}。

然後它把起始值加一，變成 2。

它把新的值 2 填入下一個位置（第 1 個位置）。向量變成 {1, 2, 0}。

然後它再把值加一，變成 3。

它把新的值 3 填入再下一個位置（第 2 個位置）。向量變成 {1, 2, 3}。

現在已經到達了容器的結尾，工人就下班了。

最後，expected_diffs 這個 vector 的內容就變成了 {1, 2, 3}。

和 for 迴圈的比較
如果不使用 iota，要達到完全相同的效果，你需要自己寫一個 for 迴圈，像這樣：

C++

// 假設 expected_diffs 是一個大小為 3 的 vector
int value = 1;
for (int i = 0; i < expected_diffs.size(); ++i) {
    expected_diffs[i] = value;
    value++;
}

// 或是更簡潔的寫法
for (size_t i = 0; i < expected_diffs.size(); ++i) {
    expected_diffs[i] = i + 1; // 索引 0 放 1，索引 1 放 2...
}
總結
std::iota 就像是上面那個 for 迴圈的快捷版。

功能：產生一個從指定值開始的連續整數序列，並填入容器。

好處：程式碼更簡潔，意圖更明確。當別人看到 iota，就能立刻明白「這裡正在產生一個連續數列」，而不需要去解讀 for 迴圈內部的邏輯。


*/