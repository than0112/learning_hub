#include <iostream>
#include <string>
#include <sstream> // 引入 stringstream，這是處理字串流的利器
#include <cctype>  // 引入 isalpha，用來判斷是否為英文字母

using namespace std;

string pig_it(string str)
{
    // --- 演算法邏輯 ---

    // 1. 建立一個 stringstream 物件來掃描輸入的句子。
    stringstream ss(str);
    
    string word;   // 用來暫時存放掃描到的每一個單字或符號。
    string result = ""; // 用來逐步建立我們最終要回傳的結果。

    // 2. 使用 while 迴圈逐一處理每個單字。
    while (ss >> word) {
        // 3. 檢查 word 是否為一個常規單字（而不是標點符號）。
        // 我們只檢查第一個字元。如果第一個字元是字母，就當作單字處理。
        if (isalpha(word[0])) {
            // a. 取出第一個字母。
            char first_letter = word[0];
            // b. 取得剩下部分的字串。
            string rest_of_word = word.substr(1);
            // c. 根據規則重新組合並加上 "ay"。
            word = rest_of_word + first_letter + "ay";
        }
        // 如果不是字母 (例如 '!' 或 '?')，我們就不對 word 做任何改變。

        // 4. 將處理好的單字加到結果中，並在前面加上空格。
        // 為了避免在句子的開頭加上多餘的空格，我們先檢查 result 是否為空。
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }

    return result;
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
