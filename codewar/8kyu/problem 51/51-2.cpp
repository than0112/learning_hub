#include <iostream>
#include <string>
#include <limits>    // 用於暫停功能
using namespace std;
string countSheep(int number) {
  // 1. 準備一個空字串 res，用來存放最終結果。
  string res = "";
  
  // 2. 使用 for 迴圈，從 1 開始，一直數到指定的 number。
  for (int i = 1; i <= number; ++i) 
    // 3. 在迴圈的每一步，都將 "i sheep..." 這個片段加到 res 字串的末尾。
    //    - std::to_string(i) 會將數字 i 轉換為字串。
    res += to_string(i) + " sheep...";
    
  // 4. 迴圈結束後，回傳組合好的完整字串。
  return res;
}
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
