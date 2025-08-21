#include <iostream>
#include <string>
#include <cstdint>   // 引入 cstdint 以使用 uint64_t 型別
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 將兩個無號 64 位元整數相加，並以二進位字串形式回傳結果 (手動轉換法)。
 * @param a 第一個非負整數。
 * @param b 第二個非負整數。
 * @return std::string 兩個數字總和的二進位表示。
 */
std::string add_binary(uint64_t a, uint64_t b) {
    // 1. 計算十進位總和。
    uint64_t sum = a + b;

    // 2. 處理邊界情況：如果總和為 0，直接回傳 "0"。
    if (sum == 0) {
        return "0";
    }

    string result = "";
    
    // 3. 使用 do-while 迴圈，透過「除以2取餘數」的方法來轉換。
    do {
      // a. (sum % 2 == 0 ? "0" : "1"): 取得餘數，並轉為字元 '0' 或 '1'。
      // b. + result: 將新算出的位數加到結果字串的「最前面」。
      result = (sum % 2 == 0 ? "0" : "1") + result; 
      
      // c. 將總和除以 2，準備處理下一位。
      sum /= 2;      
    } while (sum != 0); // 只要總和還不為 0，就繼續迴圈。
    
    return result;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param num1 第一個數字。
 * @param num2 第二個數字。
 */
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
    cout << "\n--- 其他邊界測試 ---\n";
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
