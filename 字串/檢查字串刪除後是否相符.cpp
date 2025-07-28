#include <iostream>
#include <string>

using namespace std; // 使用 std 命名空間

// 檢查 s2 是否為 s1 的子序列
bool isSubsequence(const string& s1, const string& s2) {
    auto it1 = s1.begin();
    auto it2 = s2.begin();

    while (it1 != s1.end() && it2 != s2.end()) {
        if (*it1 == *it2) {
            it2++;
        }
        it1++;
    }
    return it2 == s2.end();
}

int main() {
    string sourceStr, targetStr;
    cout << "請輸入來源字串 (較長的那個): ";
    cin >> sourceStr;
    cout << "請輸入目標字串 (較短的那個): ";
    cin >> targetStr;

    if (isSubsequence(sourceStr, targetStr)) {
        cout << "是，從 '" << sourceStr << "' 刪除字元後可以得到 '" << targetStr << "'。" << endl;
    } else {
        cout << "否，無法從 '" << sourceStr << "' 得到 '" << targetStr << "'。" << endl;
    }

    return 0;
}
/*七到十八行的解釋
程式碼的目標
這段程式碼的目標是判斷一個字串 s2 (目標字串) 是否為另一個字串 s1 (來源字串) 的「子序列」(subsequence)。

「子序列」的意思是：我們能不能從 s1 中，刪除零個或多個字元後，得到一模一樣的 s2？
重點是，s2 中字元的相對順序必須保持不變。

例如： s2 = "ace" 是 s1 = "a_b_c_d_e" 的子序列 (底線代表被刪除的字元)。

但是： s2 = "aec" 不是 s1 = "a_b_c_d_e" 的子序列，因為 'e' 和 'c' 的順序不對。

演算法：雙指標 (Two Pointers)
這個函式使用的核心技巧叫做「雙指標」。它用兩個指標（在 C++ 中稱為「迭代器」）同時在兩個字串上移動，來完成比對。

我們來逐行分解程式碼：

auto it1 = s1.begin();
auto it2 = s2.begin();

我們宣告了兩個指標，it1 和 it2。

it1 指向來源字串 s1 的開頭。

it2 指向目標字串 s2 的開頭。

while (it1 != s1.end() && it2 != s2.end()) { ... }

這是一個 while 迴圈，它會一直執行，直到其中一個指標走到了它對應字串的結尾為止。

s1.end() 代表 s1 的結尾之後的位置。

&& (AND) 的意思是，迴圈繼續的條件是 it1 和 it2 都還沒有走到結尾。

if (*it1 == *it2) { it2++; }

這是迴圈的核心邏輯。

*it1 可以取得指標 it1 當前指向的字元。

我們比較兩個指標指向的字元是否相同。

如果相同，代表我們在 s1 中找到了 s2 當前需要的一個字元。於是，我們將目標字串的指標 it2 向前移動一步 (it2++)，表示「這個字元找到了，接下來要去比對 s2 的下一個字元了」。

it1++;

不論剛剛的字元是否匹配，來源字串的指標 it1 每一次迴圈都必須向前移動一步。

這一步非常關鍵，它代表著在 s1 中「掃描」或「前進」的動作。如果字元不匹配，就相當於把 s1 的這個字元「跳過」或「刪除」了。

return it2 == s2.end();

當 while 迴圈結束時（通常是因為 it1 走完了 s1），這行程式碼就是最後的裁決。

它在檢查：「目標字串的指標 it2 是否已經成功地走到了 s2 的結尾？」

如果 it2 == s2.end() 為 true：代表 s2 中的每一個字元都已經在 s1 中按順序被找到了，it2 成功「走完」了全程。因此 s2 是 s1 的子序列。

如果為 false：代表 s1 已經從頭掃到尾了，但 it2 還沒走到 s2 的結尾，表示 s2 中還有一些字元沒被找到。因此 s2 不是 s1 的子序列。





*/