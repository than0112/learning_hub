#include <iostream>
#include <string>
#include <cmath> // 用於 pow() 和 log10() 函式

using namespace std;

/**
 
 * *  數學解釋 (Mathematical Explanation):
 * 一個 n 位數的正整數 V，如果它滿足以下條件，則被稱為水仙花數：
 * V = d_k^n + d_{k-1}^n + ... + d_1^n
 * 其中 d_i 是 V 的每一個位數上的數字，而 n 是 V 的總位數。
 * * 演算法策略 (Algorithm Strategy):
 * 1. 使用對數函式 log10() 快速計算出數字的總位數 n。
 * 2. 逐一分離出 value 的每一個位數 d。
 * 3. 計算每一個位數 d 的 n 次方，並將它們全部加總起來。
 * 4. 比較這個總和是否與原始的 value 相等。

 */
bool narcissistic( int value ){

    int num_digits = log10(value) + 1;

    // 步驟 2: 計算其每個位數的 n 次方和。
    // 使用 long long 來儲存總和，以避免在計算過程中因數字過大而產生溢位 (overflow)。
    long long sum_of_powers = 0;
    
    // 建立一個 value 的複本 temp，以便在不破壞原始 value 的情況下進行計算。
    int temp = value;

    // 使用迴圈，只要 temp 還大於 0，就代表還有位數需要處理。
    while (temp > 0) {
        // a. 取出最右邊的個位數 d。
        // 數學技巧：對 10 取餘數 (%)，可以得到最右邊的個位數。例如：153 % 10 的結果是 3。
        int digit = temp % 10;

        // b. 計算這個位數的 num_digits (n) 次方，並累加到總和中。
        sum_of_powers += pow(digit, num_digits);

        // c. 移除最右邊的個位數，為下一輪迴圈做準備。
        // 數學技巧：對 10 做整數除法 (/)，可以有效地「移除」最右邊的個位數。例如：153 / 10 的結果是 15。
        temp = temp / 10;
    }

    // 步驟 3: 驗證條件。
    // 比較計算出的總和 (sum_of_powers) 是否與原始數字 (value) 完全相等。
    return sum_of_powers == value;
}


// --- 主程式：用來測試您的 narcissistic 函式 ---
int main() {
    cout << "--- 水仙花數 (Narcissistic Number) 測試 ---\n";

    // 範例 1: 153 (3位數) -> 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153 (是)
    int test1 = 153;
    cout << test1 << " 是水仙花數嗎? " << (narcissistic(test1) ? "是 (true)" : "否 (false)") << endl;

    // 範例 2: 1652 (4位數) -> 1^4 + 6^4 + 5^4 + 2^4 = 1938 (不是)
    int test2 = 1652;
    cout << test2 << " 是水仙花數嗎? " << (narcissistic(test2) ? "是 (true)" : "否 (false)") << endl;

    // 其他測試
    int test3 = 7; // 7 (1位數) -> 7^1 = 7 (是)
    cout << test3 << " 是水仙花數嗎? " << (narcissistic(test3) ? "是 (true)" : "否 (false)") << endl;

    // 其他邊界測試
    int test4 = 9; // 9 (1位數) -> 9^1 = 9 (是)
    cout << test4 << " 是水仙花數嗎? " << (narcissistic(test4) ? "是 (true)" : "否 (false)") << endl;

    return 0;
}
