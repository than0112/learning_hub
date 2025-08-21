#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>    

using namespace std;


 
bool spEng(string sentence) {
    // --- 簡單演算法邏輯 ---

    // 1. 建立一個新的空字串，用來存放轉換後的小寫版本。
    string lower_sentence = "";

    // 2. 使用 for-each 迴圈，逐一處理原始句子中的每一個字元。
    for (char c : sentence) {
        // 將每一個字元轉為小寫後，加到新的字串中。
        lower_sentence += tolower(c);
    }

    // 3. 在轉換後的小寫字串中，尋找 "english"。
    //    string::npos 是一個特殊的值，代表「未找到」。
    //    如果 find 的結果不是 string::npos，就代表找到了。
    return lower_sentence.find("english") != string::npos;
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
