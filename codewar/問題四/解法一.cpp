#include <iostream>
#include <cmath> // 引入 cmath 函式庫，才能使用 sqrt() 函式

using namespace std;

/**
 * @brief 尋找一個完全平方數的下一個完全平方數。
 * @details 如果輸入的數字不是完全平方數，則回傳 -1。
 * @param sq 要檢查的整數。
 * @return long int 下一個完全平方數或 -1。
 */
long int findNextSquare(long int sq) {

    double root_double = sqrt(sq);

    // 2. 檢查 sq 是否為完全平方數。
    // 我們將浮點數的平方根轉換為整數，然後再平方回去。
    // 如果結果與原始數字不相等，代表平方根不是整數，因此 sq 不是完全平方數。
    // floor(root_double) 會取不大於 root_double 的最大整數。
    long int root_int = floor(root_double);
    if (root_int * root_int != sq) {
        // 如果不是完全平方數，根據題目要求回傳 -1。
        return -1;
    }

    
    long int next_root = root_int + 1;

    // 4. 回傳下一個整數的平方，這就是下一個完全平方數。
    return next_root * next_root;
}

// --- 主程式：用來測試 findNextSquare 函式 ---
int main() {
    cout << "--- 尋找下一個完全平方數 ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](long int number) {
        cout << "輸入: " << number << " --> 輸出: " << findNextSquare(number) << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(121); // 預期輸出: 144
    run_test(625); // 預期輸出: 676
    run_test(114); // 預期輸出: -1
    
    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test(0);   // 預期輸出: 1
    run_test(1);   // 預期輸出: 4
    run_test(143); // 預期輸出: -1

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    long int user_input;
    cout << "請輸入一個您想測試的非負整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的非負整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";
    return 0;
}
