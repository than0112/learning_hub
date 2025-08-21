#include <iostream>
#include <string>
#include <cctype>  
#include <limits>   // 用於暫停功能

using namespace std;


std::string to_alternating_case(const string& str)
{
  // 1. 準備一個空字串，用來存放我們轉換後的結果。
  string newStr;
  
  // 2. 使用傳統的 for 迴圈，逐一檢查原始字串中的每一個字元。
  for (size_t i = 0; i < str.length(); i++) 
  {
    // a. 檢查當前字元 str[i] 是否為大寫字母
    if (isupper(str[i])) 
    {
      // 如果是，就將其轉為小寫後，加到 newStr 中
      newStr += tolower(str[i]);
    } 
    // b. 檢查當前字元 str[i] 是否為小寫字母
    else if (islower(str[i]))
    {
      // 如果是，就將其轉為大寫後，加到 newStr 中
      newStr += toupper(str[i]);
    }
    // c. 如果既不是大寫也不是小寫
    else 
    {
      // 直接將原字元加到 newStr 中，保持不變
      newStr += str[i];
    }
  }
  // 3. 迴圈結束後，回傳建立好的新字串。
	return newStr;
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
