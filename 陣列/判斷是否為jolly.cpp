#include <iostream>
#include <vector>
#include <cmath> // 為了使用 abs 函式

using namespace std;

bool isJollyJumper(const vector<int>& seq) {
    // 取得序列的長度，存到變數 n
    int n = seq.size();
    
    // 【邊界條件處理】
    // 如果序列只有 0 個或 1 個元素，根據定義可視為 Jolly Jumper
    // 因為沒有「相鄰元素」，也就不需要檢查差值了
    if (n <= 1) {
        return true;
    }

    // 【核心技巧：建立一個「檢查清單」】
    // 我們需要檢查 1, 2, 3, ..., n-1 這些差值是否都出現了。
    // 這裡建立一個大小為 n-1 的布林(bool)向量 `found`，可以把它想像成一張檢查清單。
    // `found[0]` 用來代表差值 `1` 是否出現過。
    // `found[1]` 用來代表差值 `2` 是否出現過。
    // ...
    // `found[k]` 用來代表差值 `k+1` 是否出現過。
    // 初始化時全部設為 `false`，表示我們還沒找到任何一個差值。
    vector<bool> found(n - 1, false);

    // 【遍歷序列，計算並檢查差值】
    // 這個迴圈會走 n-1 次，取得所有的「相鄰數對」
    // 例如 [1, 4, 2, 3]，i=0 時是 (1,4)，i=1 時是 (4,2)，i=2 時是 (2,3)
    for (int i = 0; i < n - 1; ++i) {
        // 計算相鄰兩個元素的差值的「絕對值」
        int diff = abs(seq[i] - seq[i+1]);
        
        // 【合法性檢查】
        // 這是最關鍵的一步，有三種情況會讓它「不是」Jolly Jumper：
        // 1. `diff == 0`: 差值不能為 0。
        // 2. `diff >= n`: 差值必須介於 1 到 n-1 之間，超出這個範圍就不對。
        // 3. `found[diff - 1] == true`: 這表示這個差值之前已經出現過了（重複了），也不行。
        //    例如 n=5，需要差值 1,2,3,4。如果出現兩個 3，那 1,2,4 勢必有一個會缺少。
        if (diff == 0 || diff >= n || found[diff - 1]) {
            // 只要符合以上任一情況，就立刻返回 false，後面的不用再檢查了
            return false;
        }
        
        // 如果差值是合法的，就在我們的「檢查清單」上打勾
        // 把對應這個差值的位置設為 true
        found[diff - 1] = true;
    }

    // 【最終判斷】
    // 如果迴圈能順利跑完，都沒有因為任何錯誤而提前返回 false，
    // 這就代表所有相鄰差值都剛好是 1 到 n-1 的其中一個，且沒有重複。
    // 因此，它就是一個 Jolly Jumper。
    return true;
}

int main() {
    vector<int> seq1 = {1, 4, 2, 3};
    vector<int> seq2 = {1, 2, 4, 1, 5};
    vector<int> seq3 = {1, 4, 2, -1, 6};

    cout << "序列 {1, 4, 2, 3} 是 Jolly Jumper嗎? " << (isJollyJumper(seq1) ? "是" : "否") << endl;
    cout << "序列 {1, 2, 4, 1, 5} 是 Jolly Jumper嗎? " << (isJollyJumper(seq2) ? "是" : "否") << endl;
    cout << "序列 {1, 4, 2, -1, 6} 是 Jolly Jumper嗎? " << (isJollyJumper(seq3) ? "是" : "否") << endl;

    return 0;
}