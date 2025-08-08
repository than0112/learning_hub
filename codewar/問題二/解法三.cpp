#include <iostream>
#include <cmath> 

using namespace std;

bool is_square(int n) {
    // --- 演算法邏輯 ---

    // 1. 處理負數的邊界情況。
    // 負數不可能是任何整數的平方。
    if (n < 0) {
        return false;
    }

    // 2. 使用 for 迴圈逐一測試。
    // 我們從 0 開始，一個一個往上數。
    // 使用 long long 型別的 i 來避免在計算 i * i 時，因數字過大而發生整數溢位。
    for (long long i = 0; i * i <= n; ++i) {
        // 迴圈的終止條件 i * i <= n 是一個優化：
        // 如果 i 的平方已經超過了 n，那麼比 i 更大的數字的平方也一定會超過 n，
        // 就沒有必要再繼續往下找了。

        // 3. 檢查平方是否相符。
        // 如果我們找到了某個 i，它的平方剛好等於 n，
        // 那就代表 n 是一個完全平方數，我們可以立刻回傳 true 並結束函式。
        if (i * i == n) {
            return true;
        }
    }

    // 4. 如果迴圈跑完了都沒找到。
    // 如果整個迴圈都執行完畢，都沒有找到任何一個 i 的平方等於 n，
    // 那就代表 n 不是一個完全平方數，我們在函式的最後回傳 false。
    return false;
}


// --- 主程式：用來測試 is_square 函式 ---
int main() {
    cout << "--- 完全平方數判斷器 (暴力迴圈法) ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](int number) {
        cout << "數字 " << number << " 是完全平方數嗎? "
             << (is_square(number) ? "是 (true)" : "否 (false)") << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(-1);
    run_test(0);
    run_test(3);
    run_test(4);
    run_test(25);
    run_test(26);

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個您想測試的整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";
    return 0;
}
