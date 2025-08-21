#include <iostream>
#include <limits> // 用於暫停功能

using namespace std;

/**
 * @brief 根據數字的奇偶性進行不同的乘法。
 * @details 如果數字是偶數，則乘以 8；如果是奇數，則乘以 9。
 * @param a 要計算的整數。
 * @return int 計算後的結果。
 */
int simpleMultiplication(int a) {
    // --- 演算法邏輯 ---

    // 我們使用「三元運算子」，這是一個精簡的 if-else 寫法。
    // a % 2 == 0  -> 檢查 a 除以 2 的餘數是否為 0。如果是，代表 a 是偶數。
    // ? a * 8     -> 如果是偶數，就回傳 a * 8 的結果。
    // : a * 9     -> 否則 (如果是奇數)，就回傳 a * 9 的結果。
    return (a % 2 == 0) ? (a * 8) : (a * 9);
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param number 要測試的數字。
 */
void run_test(int number) {
    cout << "輸入: " << number << " -> 輸出: " << simpleMultiplication(number) << endl;
}

// --- 主程式：用來測試 simpleMultiplication 函式 ---
int main() {
    cout << "--- 簡單乘法測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(2);  // 偶數，預期輸出: 16
    run_test(1);  // 奇數，預期輸出: 9
    run_test(8);  // 偶數，預期輸出: 64
    run_test(4);  // 偶數，預期輸出: 32
    run_test(5);  // 奇數，預期輸出: 45

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個您想測試的整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
