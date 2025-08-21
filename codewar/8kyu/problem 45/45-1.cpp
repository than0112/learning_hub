#include <iostream>
#include <string>
#include <cstdint>    // 引入 uint64_t 類型
#include <algorithm> // 引入 reverse 函式
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 將兩個無號 64 位元整數相加，並以二進位字串形式回傳結果。
 * @param a 第一個非負整數。
 * @param b 第二個非負整數。
 * @return std::string 兩個數字總和的二進位表示。
 */
string add_binary(uint64_t a, uint64_t b) {
    // --- 演算法邏輯 ---

    // 1. 首先，計算兩個數字的十進位總和。
    uint64_t sum = a + b;

    // 2. 處理邊界情況：如果總和為 0，直接回傳 "0"。
    if (sum == 0) {
        return "0";
    }

    // 3. 準備一個空字串，用來存放二進位的結果。
    string binary_result = "";

    // 4. 使用 while 迴圈，透過「除以2取餘數」的方法來轉換。
    //    只要總和還大於 0，就繼續迴圈。
    while (sum > 0) {
        // a. sum % 2 會得到 0 或 1，這就是二進位的最低位。
        //    我們將它轉為字元 '0' 或 '1'，並加到結果字串的末尾。
        binary_result += (sum % 2 == 0 ? "0" : "1");

        // b. 將總和除以 2 (整數除法)，捨去最低位，準備處理下一位。
        sum /= 2;
    }

    // 5. 反轉結果字串。
    //    因為我們是從最低位開始建立字串的，所以得到的順序是反的，
    //    需要將其反轉回來才是正確的二進位表示。
    reverse(binary_result.begin(), binary_result.end());

    return binary_result;
}
void run_test(uint64_t num1, uint64_t num2) {
    cout << "輸入: (" << num1 << ", " << num2 << ") -> 輸出: \"" 
         << add_binary(num1, num2) << "\"" << endl;
}

// --- 主程式：用來測試 add_binary 函式 ---
int main() {
    cout << "--- 二進位加法測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(1, 1); // 預期輸出: "10"
    run_test(5, 9); // 預期輸出: "1110"

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊-界測試 ---\n";
    run_test(0, 0);   // 預期輸出: "0"
    run_test(51, 13); // 51+13 = 64 -> 預期輸出: "1000000"

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
