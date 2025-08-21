#include <iostream>
#include <string>
#include <numeric> 
#include <cmath>   

using namespace std;

/**
 * @brief 使用 std::accumulate 和 Lambda 函式判斷水仙花數。
 * @param n 要檢查的正整數。
 * @return bool 如果是水仙花數則回傳 true，否則回傳 false。
 */
bool narcissistic(int n)
{
    // 防護機制：根據定義，水仙花數為正整數。
    if (n <= 0) {
        return false;
    }

    string s = to_string(n);

    // 使用 std::accumulate 進行累加計算
    // - s.cbegin(), s.cend(): 迭代範圍是字串的頭到尾
    // - 0LL: 這是最重要的修正！使用 0LL (long long) 作為初始值，
    //        可以確保累加器 sum 的型別是 long long，避免整數溢位。
    // - [&s](...){...}: 使用傳址參考捕獲字串 s，效率更高。
    long long sum_of_powers = accumulate(s.cbegin(), s.cend(), 0LL, [&s](long long sum, char v){
        // v - '0' 是將字元轉為數字的標準作法
        return sum + pow(v - '0', s.size());
    });

    return n == sum_of_powers;
}

// --- 主程式：用來測試您的 narcissistic 函式 ---
int main() {
    cout << "--- 水仙花數 (accumulate 函數式寫法) 測試 ---\n";

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

