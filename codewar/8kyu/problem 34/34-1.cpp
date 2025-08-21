#include <iostream>
#include <string>
#include <limits> // 用於暫停功能

using namespace std;
string boolean_to_string(bool b){
   
    return b ? "true" : "false";
}
void run_test(bool value) {
    cout << "輸入: " << (value ? "true" : "false") 
         << " -> 輸出: \"" << boolean_to_string(value) << "\"" << endl;
}

// --- 主程式：用來測試 boolean_to_string 函式 ---
int main() {
    cout << "--- 布林值轉字串測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(true);
    run_test(false);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
