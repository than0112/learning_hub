#include <iostream>

using namespace std;

/**
 * @brief 一個自訂的整數次方函式，以避免浮點數運算。
 * @param base 基底。
 * @param exp 指數。
 * @return long long 計算結果 (使用 long long 以容納較大的數值)。
 */
long long integerPower(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

/**
 * @brief 使用雙迴圈純整數計算法判斷水仙花數。
 * @param value 要檢查的正整數。
 * @return bool 如果是水仙花數則回傳 true，否則回傳 false。
 */
bool narcissistic(int value) {
    if (value <= 0) {
        return false;
    }

    // --- 步驟 1: 第一個迴圈，計算數字的總位數 ---
    int num_digits = 0;
    int temp = value; // 使用複本進行計算
    while (temp > 0) {
        temp /= 10;
        num_digits++;
    }

    // --- 步驟 2: 第二個迴圈，計算各位數的次方和 ---
    // **修正：使用 long long 作為累加器以避免溢位**
    long long sum_of_powers = 0;
    temp = value; // 重設複本
    while (temp > 0) {
        int digit = temp % 10;
        sum_of_powers += integerPower(digit, num_digits);
        temp /= 10;
    }
    
    // --- 步驟 3: 比較結果 ---
    // **修正：移除多餘的條件判斷**
    return sum_of_powers == value;
}

// --- 主程式：用來測試您的 narcissistic 函式 ---
int main() {
    cout << "--- 水仙花數 (雙迴圈純整數計算法) 測試 ---\n";

    // 範例 1: 153 (是)
    int test1 = 153;
    cout << test1 << " 是水仙花數嗎? " << (narcissistic(test1) ? "是 (true)" : "否 (false)") << endl;

    // 範例 2: 1652 (不是)
    int test2 = 1652;
    cout << test2 << " 是水仙花數嗎? " << (narcissistic(test2) ? "是 (true)" : "否 (false)") << endl;

    // 範例 3: 9926315 (是)
    int test3 = 9926315;
    cout << test3 << " 是水仙花數嗎? " << (narcissistic(test3) ? "是 (true)" : "否 (false)") << endl;

    return 0;
}
