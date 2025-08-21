#include <iostream>
#include <string>
#include <cmath>   // 用於 pow() 和 log10() 函式

using namespace std;

// 使用 namespace 來組織函式，這是一種常見的作法
namespace DigPow {
    /**
     * @brief 使用逆向數學計算法，檢查一個數字 n 的各位數的 p, p+1, ... 次方和，是否為 n 的 k 倍。
     * @param n 一個正整數。
     * @param p 一個正整數，作為起始次方。
     * @return int 如果存在，則回傳 k；否則回傳 -1。
     */
    int digPow(int n, int p)
    {
        // 1. 技巧性地計算出最高次方數。
        // log10(n) 的整數部分是 n 的位數減一。
        // p 加上這個值，就得到了最左邊位數所對應的最高次方。
        // 注意：這裡的 p 會變成一個浮點數。
        double power = p + floor(log10(n));

        // 2. 初始化一個 long long 型別的變數來儲存次方和，以避免溢位。
        long long sum = 0;
        int temp = n; // 使用複本進行計算

        // 3. 從右到左（個位數開始）遍歷每一位數，同時遞減次方。
        while (temp > 0) {
            int digit = temp % 10;
            sum += pow(digit, power);
            temp /= 10;
            power--;
        }

        // 4. 檢查總和 sum 是否為 n 的整數倍，並回傳結果。
        // 使用三元運算子讓程式碼更簡潔。
        return (sum % n == 0) ? (sum / n) : -1;
    }
};
void run_test_digpow(int n, int p) {
    cout << "輸入: n = " << n << ", p = " << p 
         << " --> 輸出: " << DigPow::digPow(n, p) << endl;
}

// --- 主程式：用來測試 digPow 函式 ---
int main() {
    cout << "--- Playing with digits 測試器 (逆向數學計算法) ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test_digpow(89, 1);    // 預期輸出: 1
    run_test_digpow(92, 1);    // 預期輸出: -1
    run_test_digpow(695, 2);   // 預期輸出: 2
    run_test_digpow(46288, 3); // 預期輸出: 51

    cout << "\n測試結束。\n";
    return 0;
}
