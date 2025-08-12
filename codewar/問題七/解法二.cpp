#include <iostream>

using namespace std;

/**
 * @brief 使用緊湊的巢狀 for 迴圈計算「乘法持久性」。
 * @param n 一個正整數。
 * @return int 乘法的次數。
 */
int persistence(long long n) {
    int steps = 0;
    
    // 外層迴圈：只要 n 還是多位數 (n > 9)，就繼續。
    // - 初始化: sum = 1 (只執行一次)
    // - 條件: n > 9
    // - 迭代表達式: 在內層迴圈結束後，更新 n, 重設 sum, 並增加 steps。
    for (long long sum = 1; n > 9; n = sum, sum = 1, steps++) {
        
        // 內層迴圈：計算當前 n 的各位數乘積，存入 sum 中。
        // 這個迴圈會一直執行，直到把 n 的所有位數都處理完 (n 變為 0)。
        for (; n > 0; n /= 10) {
            sum *= (n % 10);
        }
        // 內層迴圈結束後，控制權交還給外層迴圈的「迭代表達式」。
    }
    
    return steps;
}

// --- 主程式：用來測試 persistence 函式 ---
int main() {
    cout << "--- 乘法持久性測試器 (緊湊迴圈法) ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](long long number) {
        cout << "輸入: " << number << " --> 輸出: " << persistence(number) << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(39);  // 預期輸出: 3
    run_test(999); // 預期輸出: 4
    run_test(4);   // 預期輸出: 0
    
    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test(27);  // 預期輸出: 2
    run_test(10);  // 預期輸出: 1

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    long long user_input;
    cout << "請輸入一個您想測試的正整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的正整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";
    return 0;
}
