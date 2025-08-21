#include <iostream>
#include <string>
#include <algorithm> 
#include <limits>    // 用於暫停功能

using namespace std;
string no_space(const string& x)
{
  
    string result = "";
    
    // 遍歷原始字串 x 中的每一個字元
    for (char c : x)
    {
        // 如果當前字元不是空格...
        if (c != ' ')
        {
            // ...就將它加到我們的結果字串中。
            result += c;
        }
    }
    
    // 回傳建立好的、不含空格的新字串。
    return result;
}
void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: \"" << no_space(input) << "\"" << endl;
}

// --- 主程式：用來測試 no_space 函式 ---
int main() {
    cout << "--- 移除空格測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("8 j 8   mBliB8g  imjB8B8  jl  B");
    run_test("8 8 Bi fk8h B 8 BB8B B B  B888 c hl8 BhB fd");
    run_test("8aaaaa dddd r     ");

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
