/*題目敘述
A Narcissistic Number (or Armstrong Number) is a positive number which is the sum of its own digits, each raised to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10).
For example, take 153 (3 digits), which is narcissistic:

1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
and 1652 (4 digits), which isn't:

1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938
The Challenge:

Your code must return true or false (not 'true' and 'false') depending upon whether the given number is a Narcissistic number in base 10.

This may be True and False in your language, e.g. PHP.

Error checking for text strings or other invalid inputs is not required, only valid positive non-zero integers will be passed into the function.*/
#include <iostream>
#include <string>
#include <cmath> // 用於 pow() 函式來計算次方

using namespace std;

/**
 * @brief 判斷一個數是否為水仙花數 (Narcissistic Number)。
 * @param value 要檢查的正整數。
 * @return bool 如果是水仙花數則回傳 true，否則回傳 false。
 */
bool narcissistic(int value) {
    // --- 程式碼從這裡開始 ---

    // 步驟 1: 取得這個數字是幾位數。
    // 最簡單的方法是將數字轉換成字串，然後取得其長度。
    string s = to_string(value);
    int num_digits = s.length();

    // 步驟 2: 計算各位數字的「位數」次方和。
    // 我們需要一個變數來儲存加總的結果。使用 long long 以避免中間計算溢位。
    long long sum_of_powers = 0;
    
    // 我們需要一個暫存的變數來逐一取出數字，才不會動到原始的 value
    int temp = value;

    // 使用迴圈，只要 temp 還大於 0，就繼續處理
    while (temp > 0) {
        // a. 取出最右邊的個位數 (例如 153 -> 3)
        int digit = temp % 10;

        // b. 計算這個數字的 num_digits 次方，並加到總和中
        sum_of_powers += pow(digit, num_digits);

        // c. 移除最右邊的個位數 (例如 153 -> 15)
        temp = temp / 10;
    }

    // 步驟 3: 比較計算出來的總和是否與原始數字相等。
    // 這個比較運算式本身就會回傳 true 或 false。
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

    int test4 = 371; // 371 (3位數) -> 3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371 (是)
    cout << test4 << " 是水仙花數嗎? " << (narcissistic(test4) ? "是 (true)" : "否 (false)") << endl;

    int test5 = 12; // 12 (2位數) -> 1^2 + 2^2 = 1 + 4 = 5 (不是)
    cout << test5 << " 是水仙花數嗎? " << (narcissistic(test5) ? "是 (true)" : "否 (false)") << endl;

    return 0;
}
