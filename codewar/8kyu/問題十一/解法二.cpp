#include <iostream>
#include <string>
#include <cmath>   // 用於 pow() 函式
#include <vector>

using namespace std;

class DigPow
{
public:
    /**
     * @brief 檢查一個數字 n 的各位數的 p, p+1, ... 次方和，是否為 n 的 k 倍。 (精簡版)
     * @param n 一個正整數。
     * @param p 一個正整數，作為起始次方。
     * @return int 如果存在，則回傳 k；否則回傳 -1。
     */
    static int digPow(int n, int p){
        // 初始化一個 long long 型別的變數來儲存次方和，以避免溢位。
        long long sum = 0;

        // 使用 C++11 的 range-based for loop 直接遍歷 to_string(n) 產生的臨時字串。
        // 這種寫法非常現代且簡潔。
        for(char digit_char : to_string(n)){
            // 1. (digit_char - '0'): 將字元轉換為對應的整數。
            // 2. p++: 使用「後置遞增」，代表會先使用 p 當前的值來計算次方，
            //    然後 p 的值才會加一，準備給下一次迴圈使用。
            sum += pow(digit_char - '0', p++);
        }
        
        // 使用「三元運算子」來回傳結果，這是一個精簡的 if-else 寫法。
        // (sum / n) * n == sum 是一種檢查 sum 是否為 n 的整數倍的技巧。
        // 如果是，整數除法再乘回來會等於原來的 sum；如果不是，則會因小數被捨去而不相等。
        return (sum / n) * n == sum ? sum / n : -1;
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
/*DigPow::digPow這一個部分就是呼叫一個名為DigPow的工具箱裡面的digPow工具去處理問題 */

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
