#include <iostream>
#include <string>
#include <algorithm> // 使用 remove
#include <limits>    // 用於暫停功能
using namespace std;
string removeExclamationMarks(string str){
  
    /*remove(str.begin(), str.end(), '!')
        - 這個函式會遍歷整個字串。
        - 它會將所有「不是」驚嘆號的字元，全部移動到字串的前端。
        - 它會回傳一個「迭代器」，指向處理過後的新字串的結尾位置。
        - 例如："H!e!llo" -> "Hello!!" (前面的 "Hello" 是移動過的，後面的 "!!" 是遺留下來的)
  
    2. str.erase(...)
       - 這個函式會接收 `remove` 回傳的那個新結尾位置，
        - 並將從那個位置開始，到原始字串結尾的所有字元全部刪除。
    str.erase(remove(str.begin(), str.end(), '!'), str.end());
    
     3. 回傳已經被修改過的字串。*/
    return str;
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
