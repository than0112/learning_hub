#include <iostream>
#include <string>
#include <algorithm> 
#include <limits>    // 用於暫停功能

using namespace std;
unsigned int strCount(const string& word, char letter){
   
    return count(word.begin(), word.end(), letter);
}

void run_test(const string& text, char character) {
    cout << "輸入: (\"" << text << "\", '" << character << "')  =>  輸出: " 
         << strCount(text, character) << endl;
}

// --- 主程式：用來測試 strCount 函式 ---
int main() {
    cout << "--- 字元計數器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("Hello", 'o');
    run_test("Hello", 'l');
    run_test("", 'z');
    run_test("Pneumonoultramicroscopicsilicovolcanoconiosis", 's');

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
