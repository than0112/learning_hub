#include <iostream>
#include <string>
#include <cctype>   // 引入 toupper() 函式，用於處理大小寫
#include <algorithm> // 引入 algorithm 以便使用其功能
#include <limits>   // 用於暫停功能

using namespace std;
bool isPalindrom (const std::string& str) {
  // --- 演算法邏輯：複製-反轉-比較法 ---

  // 1. 建立一個原始字串的複本，以便進行修改而不影響原始資料。
  std::string lstr = str;

    // 2. 將複本轉為大寫，這樣就不需要在比較時考慮大小寫差異。
  for (char& c : lstr) {
      c = toupper(c);
  }
  
  
  return lstr == std::string(lstr.rbegin(), lstr.rend());
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param text 要測試的字串。
 */
void run_test(const string& text) {
    cout << "輸入: \"" << text << "\" -> 輸出: " 
         << (isPalindrom(text) ? "true" : "false") << endl;
}

// --- 主程式：用來測試 isPalindrom 函式 ---
int main() {
    cout << "--- 迴文判斷器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("madam");   // 預期: true
    run_test("racecar"); // 預期: true
    run_test("Aba");     // 預期: true (不分大小寫)
    run_test("hello");   // 預期: false
    run_test("a");       // 預期: true
    
    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個您想測試的單字: ";
    cin >> user_input;
    run_test(user_input);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
