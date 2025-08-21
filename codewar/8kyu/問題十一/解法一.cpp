#include <iostream>
#include <string>
#include <cmath>   // 用於 pow() 函式
#include <vector>

using namespace std;

class DigPow
{
public:
    /**
     * @brief 檢查一個數字 n 的各位數的 p, p+1, ... 次方和，是否為 n 的 k 倍。
     * @param n 一個正整數。
     * @param p 一個正整數，作為起始次方。
     * @return int 如果存在，則回傳 k；否則回傳 -1。
     */
    static int digPow(int n, int p) {
        // --- 演算法邏輯 ---

        // 1. 將數字 n 轉換為字串，方便我們逐一取得每個位數。
        string s = to_string(n);

        // 2. 初始化一個 long long 型別的變數來儲存次方和。
        //    使用 long long 是為了防止計算過程中因數字過大而產生溢位。
        long long sum = 0;

        // 3. 遍歷字串中的每一個字元 (位數)。
        for (char c : s) {
            // a. 將字元轉換回它所代表的整數。
            int digit = c - '0';
            
            // b. 計算 (位數 ^ p)，並累加到 sum 中。
            sum += pow(digit, p);
            
            // c. 將次方 p 加一，為下一個位數做準備。
            p++;
        }

        // 4. 檢查總和 sum 是否可以被 n 整除。
        // a. `sum % n == 0` 檢查餘數是否為 0。
        if (sum % n == 0) {
            // 如果可以整除，k 就存在，其值為 sum / n。
            return sum / n;
        } else {
            // 如果不能整除，k 不存在，根據題目要求回傳 -1。
            return -1;
        }
    }
};

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param n 要測試的數字。
 * @param p 要測試的起始次方。
 */
void run_test_digpow(int n, int p) {
    cout << "輸入: n = " << n << ", p = " << p 
         << " --> 輸出: " << DigPow::digPow(n, p) << endl;
}

// --- 主程式：用來測試 digPow 函式 ---
int main() {
    cout << "--- Playing with digits 測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test_digpow(89, 1);    // 預期輸出: 1
    run_test_digpow(92, 1);    // 預期輸出: -1
    run_test_digpow(695, 2);   // 預期輸出: 2
    run_test_digpow(46288, 3); // 預期輸出: 51

    cout << "\n測試結束。\n";
    return 0;
}
