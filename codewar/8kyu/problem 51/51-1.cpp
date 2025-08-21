#include <iostream>
#include <string>
#include <sstream>   // 引入 stringstream，用於高效地組合字串
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 根據給定的數字 n，產生一句 "1 sheep...2 sheep...n sheep..." 的字串。
 * @param number 一個非負整數。
 * @return std::string 組合好的「數羊」字串。
 */
std::string countSheep(int number) {
    // 1. 準備一個 stringstream 物件，這是一個高效的「字串組合器」。
    stringstream ss;

    // 2. 使用 for 迴圈，從 1 開始，一直數到指定的 number。
    for (int i = 1; i <= number; ++i) {
        // 3. 在迴圈的每一步，都將 "i sheep..." 這個片段加到組合器中。
        ss << i << " sheep...";
    }

    // 4. 迴圈結束後，使用 .str() 方法，將組合器中的所有內容轉換為一個完整的字串並回傳。
    return ss.str();
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param num 要測試的數字。
 */
void run_test(int num) {
    cout << "輸入: " << num << " -> 輸出: \"" << countSheep(num) << "\"" << endl;
}

// --- 主程式：用來測試 countSheep 函式 ---
int main() {
    cout << "--- 數羊產生器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(1);
    run_test(2);
    run_test(3);
    run_test(0); // 測試邊界情況

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
