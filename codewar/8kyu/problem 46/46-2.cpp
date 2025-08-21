#include <iostream>
#include <string>
#include <limits> // 用於暫停功能

using namespace std;
string fakeBin(string str){
  for (int i = 0; i < str.length(); i++)
  {
  
    str[i] = ((str[i] - '0') > 4) ? '1' : '0';
  }
  // 回傳已經被完整修改過的字串。
  return str;
}

void run_test(const string& input) {
    cout << "輸入: \"" << input << "\" -> 輸出: \"" << fakeBin(input) << "\"" << endl;
}

// --- 主程式：用來測試 fakeBin 函式 ---
int main() {
    cout << "--- 偽二進位轉換器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("45385593107843568");
    run_test("509321967506747");
    run_test("366058562030849490134388085");

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一串您想轉換的數字 (輸入 'q' 結束): ";
    while (cin >> user_input && user_input != "q") {
        run_test(user_input);
        cout << "\n請繼續輸入 (輸入 'q' 結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}

