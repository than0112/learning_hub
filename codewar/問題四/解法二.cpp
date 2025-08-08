#include <iostream>
#include <cmath> // 引入 cmath 函式庫，才能使用 sqrt() 和 pow() 函式

using namespace std;

/**
 * @brief 尋找下一個完全平方數。
 * @details 使用 C++ 的型別轉換特性來判斷一個數是否為完全平方數。
 * @param sq 一個非負整數。
 * @return long int 下一個完全平方數，或者 -1。
 */
long int findNextSquare(long int sq) {
    // --- 演算法邏輯 ---

    // 1. 處理負數的邊界情況。
    if (sq < 0) {
        return -1;
    }

    // 2. 計算平方根。
    double root = sqrt(sq);

    if (root != (int)root) {
        return -1;
    }

    return pow(root + 1, 2);
}

// --- 主程式：用來測試 findNextSquare 函式 ---
int main() {
    cout << "--- 尋找下一個完全平方數 ---\n";

    
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
