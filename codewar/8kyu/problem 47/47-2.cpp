#include <iostream>
#include <string>
#include <algorithm> 
#include <limits>    // 用於暫停功能

using namespace std;

string removeExclamationMarks(string str){
   
    string clean = "";
    
    // 2. 使用 for 迴圈遍歷原始字串中的每一個字元。
    for (size_t i = 0; i < str.length(); i++)
    {
        // 3. 檢查當前字元 str[i] 是否「不是」驚嘆號。
        if (str[i] != '!')
        {
            // 4. 如果不是驚嘆號，就將這個字元加到 clean 字串的末尾。
            clean += str[i];
        }
    }
    
    // 5. 迴圈結束後，回傳建立好的、不含驚嘆號的新字串。
    return clean;
}

void run_test(const string& input) {
    cout << "輸入: \"" << input << "\" -> 輸出: \"" << removeExclamationMarks(input) << "\"" << endl;
}

// --- 主程式：用來測試 removeExclamationMarks 函式 ---
int main() {
    cout << "--- 移除驚嘆號測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("Hello World!");
    run_test("Hi! Hello!");
    run_test("!Hi! Hi!");
    run_test("Oh, no!!!");

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
