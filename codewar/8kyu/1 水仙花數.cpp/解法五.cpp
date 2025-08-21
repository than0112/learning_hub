#include <iostream>
#include <vector>
#include <cmath> // 用於 pow()

using namespace std;
bool narcissistic(int value)
{
    if (value <= 0) {
        return false;
    }
    vector<int> digits;
    int temp = value; // 使用一個複本來進行拆解

    // **修正後的迴圈邏輯**
    // 只要 temp 還大於 0，就繼續拆解
    while (temp > 0) {
        digits.push_back(temp % 10); // 取出個位數並存入 vector
        temp /= 10;                  // 移除個位數
    }

    // --- 步驟 2: 計算次方和 ---
    // 數字的總位數就是 vector 的大小
    int num_digits = digits.size();
    
  
    // 使用 long long 來避免計算過程中發生整數溢位
    long long sum_of_powers = 0;

    // 使用 for-each 迴圈遍歷 vector 中的每一個位數
    for (int digit : digits) {
        sum_of_powers += pow(digit, num_digits);
    }
    
    // --- 步驟 3: 比較結果 ---
    return sum_of_powers == value;
}

int main() {
    cout << "--- 水仙花數 (Vector 拆解法) 測試 ---\n";

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
