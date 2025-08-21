#include <iostream>
#include <string>
#include <sstream> // 保留，以備不時之需
#include <cctype>  // 保留，以備不時之_需
#include <regex>   // 引入正規表示式函式庫

using namespace std;

/**
 * @brief 將一個句子轉換為豬拉丁文 (正規表示式法)。
 * @details 使用正規表示式來尋找每一個單字，並根據指定格式進行替換。
 * @param str 原始的句子字串。
 * @return string 轉換後的豬拉丁文句子。
 */
string pig_it(string str)
{
    // 1. 定義一個正規表示式規則。
    // (\\w): 捕獲第一個單字字元 (字母或數字) -> $1
    // (\\w*): 捕獲剩下的零個或多個單字字元 -> $2
    // (\\s|$): 捕獲單字後面的空白或句尾 -> $3
    regex reg("(\\w)(\\w*)");

    // 2. 使用 regex_replace 進行全域的搜尋與取代。
    // "$2$1ay" 是取代的格式：
    // $2: 剩下的字
    // $1: 第一個字母
    // ay: 固定的字尾
    // 這種寫法會自動處理所有單字，但不會處理標點符號。
    return regex_replace(str, reg, "$2$1ay");
}

// --- 主程式：用來測試 pig_it 函式 ---
int main() {
    cout << "--- 豬拉丁文 (Pig Latin) 轉換器 ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](const string& input) {
        cout << "輸入: \"" << input << "\" \n--> 輸出: \"" << pig_it(input) << "\"" << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("Pig latin is cool"); // 預期輸出: "igPay atinlay siay oolcay"
    run_test("Hello world !");     // 預期輸出: "elloHay orldway !"
    run_test("This is a test");    // 預期輸出: "hisTay siay aay esttay"

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個英文句子: ";
    // 使用 getline 讀取一整行，這樣才能處理包含空格的句子
    getline(cin, user_input);
    run_test(user_input);

    cout << "\n測試結束。\n";
    return 0;
}
