#include <iostream>
#include <string>
#include <cctype>   
#include <limits>  
using namespace std;
std::string to_alternating_case(std::string str) // 注意：參數是傳值(pass-by-value)，所以我們操作的是一個複本
{
  
  for(auto& ch : str)
  {
    // 使用三元運算子來完成轉換：
    // 如果 islower(ch) 為 true (字元是小寫)，就將其轉為大寫 toupper(ch)。
    // 否則 (字元是大寫或非字母)，就將其轉為小寫 tolower(ch)。
    // tolower 對於一個已經是大寫的字母會轉為小寫，對於非字母字元則不會改變它。
    ch = std::islower(ch) ? std::toupper(ch) : std::tolower(ch);
  }
  // 回傳已經被完整修改過的 str 字串複本。
  return str;
}
void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: \"" << to_alternating_case(input) << "\"" << endl;
}

// --- 主程式：用來測試 to_alternating_case 函式 ---
int main() {
    cout << "--- 大小寫交錯轉換器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("hello world");
    run_test("HELLO WORLD");
    run_test("hello WORLD");
    run_test("HeLLo WoRLD");
    run_test("12345");
    run_test("1a2b3c4d5e");
    run_test("String.prototype.toAlternatingCase");

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個您想測試的字串: ";
    getline(cin, user_input);
    run_test(user_input);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
