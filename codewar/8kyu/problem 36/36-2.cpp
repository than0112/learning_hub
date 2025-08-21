#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>    // 引入 tolower

using namespace std;
bool spEng(string sentence) { // 注意：參數是傳值(pass-by-value)，所以我們操作的是一個複本
    // --- 更簡單的演算法邏輯 ---

    // 1. 直接在傳入的字串複本上，將所有字元轉為小寫。
    //    `for (char &c : ...)` 中的 '&' 代表參考，讓我們可以直接修改字串中的字元。
    for (char &c : sentence) {
        c = tolower(c);
    }

    // 2. 在轉換後的小寫字串中，尋找 "english"。
    //    string::npos 是一個特殊的值，代表「未找到」。
    //    如果 find 的結果不是 string::npos，就代表找到了。
    return sentence.find("english") != string::npos;
}

void run_test(const string& input) {
    cout << "輸入: \"" << input << "\" -> 輸出: " 
         << (spEng(input) ? "true" : "false") << endl;
}

// --- 主程式：用來測試 spEng 函式 ---
int main() {
    cout << "--- Spoken English 測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("english");
    run_test("abcEnglishdef");
    run_test("eNglisH");
    run_test("abcnEglishsef"); // 拼字錯誤，應為 false
    run_test("I speak English.");
    run_test("no english here");
    run_test("Spanish"); // 不包含完整的 "english"

    cout << "\n測試結束。\n";
    return 0;
}
