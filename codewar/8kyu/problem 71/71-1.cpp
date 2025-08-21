/*Write a function which converts the input string to uppercase*/
#include <iostream>
#include <string>
#include <cctype>   // 必須引入 cctype 才能使用 toupper
#include <limits>   // 用於暫停功能

using namespace std;
string makeUpperCase (const string& input_str)
{
    // 1. 準備一個空字串，用來存放結果。
    string result = "";
    
    // 2. 使用 for-each 迴圈，逐一處理原始字串中的每一個字元。
    for (char c : input_str) {
        // 3. 將每一個字元 c 轉換為大寫後，加到 result 字串中。
        //    toupper() 函式會將小寫字母轉為大寫，其他字元則保持不變。
        result += toupper(c);
    }
    
    // 4. 迴圈結束後，回傳建立好的新字串。
    return result;
}
void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: \"" << makeUpperCase(input) << "\"" << endl;
}

// --- 主程式：用來測試 makeUpperCase 函式 ---
int main() {
    cout << "--- 字串轉大寫測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("hello");
    run_test("Hello World");
    run_test("123 Hello");

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
