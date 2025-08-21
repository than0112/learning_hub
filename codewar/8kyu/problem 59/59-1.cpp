#include <iostream>
#include <string>
#include <vector>
#include <limits>    // 用於暫停功能
using namespace std;
string double_char(const string& str)
{
    // 1. 準備一個空字串，用來存放結果。
    string result = "";

    // 2. 使用 for-each 迴圈，逐一處理原始字串中的每一個字元。
    for (char c : str) {
        // 3. 將每一個字元 c 連續兩次加到 result 向量中。
        result += c;
        result += c;  // 重複一次
        
    }

    // 4. 迴圈結束後，回傳建立好的完整字串。
    return result;
}

void run_test(const string& input) {
    cout << "輸入: \"" << input << "\" -> 輸出: \"" << double_char(input) << "\"" << endl;
}

// --- 主程式：用來測試 double_char 函式 ---
int main() {
    cout << "--- 重複字元測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("String");
    run_test("Hello World");
    run_test("1234!_ ");

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
