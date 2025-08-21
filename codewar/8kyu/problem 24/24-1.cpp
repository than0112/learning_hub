#include <iostream>
#include <string>
#include <limits> // 用於暫停功能

using namespace std;

/**
 * @brief 計算一個非負整數的二進位表示中，位元 '1' 的數量。
 * @param n 要計算的非負整數 (unsigned long long)。
 * @return unsigned int 位元 '1' 的總數。
 */
unsigned int countBits(unsigned long long n) {
    // --- 演算法邏輯：逐一檢查位元 ---

    // 1. 初始化一個計數器，用來記錄 '1' 的數量。
    unsigned int count = 0;

    // 2. 使用一個 while 迴圈，只要數字 n 還不為 0，就繼續檢查。
    while (n > 0) {
        // a. 使用位元 AND 運算 (&) 來檢查最右邊的位元。
        //    n & 1 的結果只可能是 1 (如果 n 的最右邊位元是 1) 或 0。
        if ((n & 1) == 1) {
            // 如果最右邊的位元是 1，計數器就加一。
            count++;
        }

        // b. 使用右移運算子 (>>) 將 n 的所有位元向右移動一位。
        //    這相當於捨去最右邊的位元，讓我們可以在下一輪迴圈檢查新的最右邊位元。
        n >>= 1; // 等同於 n = n >> 1;
    }

    // 3. 當 n 變為 0 時，代表所有位元都已檢查完畢，回傳最終的計數。
    return count;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param number 要測試的數字。
 */
void run_test(unsigned long long number) {
    cout << "輸入: " << number << " -> 輸出: " << countBits(number) << endl;
}

// --- 主程式：用來測試 countBits 函式 ---
int main() {
    cout << "--- 位元計數器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(1234); // 預期輸出: 5 (二進位 10011010010)

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test(0);    // 預期輸出: 0
    run_test(4);    // 預期輸出: 1 (二進位 100)
    run_test(7);    // 預期輸出: 3 (二進位 111)
    run_test(9);    // 預期輸出: 2 (二進位 1001)
    run_test(10);   // 預期輸出: 2 (二進位 1010)

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    unsigned long long user_input;
    cout << "請輸入一個您想測試的非負整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的非負整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
