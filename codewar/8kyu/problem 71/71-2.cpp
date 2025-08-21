#include <iostream>
#include <string>
#include <cctype>   
#include <limits>   // 用於暫停功能

using namespace std;
string makeUpperCase (const string& input_str)
{
    // 1. 準備一個空字串 ret，用來存放結果。
    string ret;
    
    // 2. 使用 for-each 迴圈，逐一處理原始字串中的每一個字元。
    //    auto& ch 中的 '&' 代表參考，讓我們可以直接存取字元。
    for(auto &ch :input_str)
    {
        // 3. 將每一個字元 ch 轉換為大寫後，
        //    使用 push_back 將其附加到 ret 字串的末尾。
        ret.push_back(toupper(ch));
    }
    
    // 4. 迴圈結束後，回傳建立好的新字串。
    return ret;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param input 要測試的字串。
 */
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
