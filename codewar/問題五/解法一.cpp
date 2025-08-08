#include <iostream>
#include <string>
#include <sstream>   // 引入 stringstream，這是處理字串流的利器
#include <algorithm> // 引入 algorithm，才能使用 reverse() 函式

using namespace std;
string spinWords(const string &str)
{
    // --- 演算法邏輯 ---

    // 1. 建立一個 stringstream 物件。
    // 生活化解釋：這就像一個掃描器，可以方便地從一個長字串中，
    // 一個一個地把單字（以空白分隔）掃描出來。
    stringstream ss(str);
    
    // 2. 準備兩個字串變數。
    string word;   // 用來暫時存放掃描到的每一個單字。
    string result = ""; // 用來逐步建立我們最終要回傳的結果。

    // 3. 使用 while 迴圈逐一處理每個單字。
    // `ss >> word` 會從 stringstream 中讀取下一個單字，
    // 如果成功讀到，迴圈繼續；如果都讀完了，迴圈結束。
    while (ss >> word) {
        // 4. 檢查單字的長度。
        if (word.length() >= 5) {
            // 如果長度大於或等於 5，就反轉這個單字。
            // reverse() 函式需要一對「迭代器」來指定要反轉的範圍，
            // word.begin() 和 word.end() 分別代表單字的頭和尾。
            reverse(word.begin(), word.end());
        }

        // 5. 將處理好的單字加到結果中。
        // 為了避免在句子的開頭加上多餘的空格，我們先檢查 result 是否為空。
        if (!result.empty()) {
            result += " "; // 如果 result 不是空的，就在加入新單字前先加一個空格。
        }
        result += word;
    }

    return result;
}

// --- 主程式：用來測試 spinWords 函式 ---
int main() {
    cout << "--- 反轉單字 (Spin Words) ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](const string& input) {
        cout << "輸入: \"" << input << "\" \n--> 輸出: \"" << spinWords(input) << "\"" << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("Hey fellow warriors");      // 預期輸出: "Hey wollef sroirraw"
    run_test("This is a test");          // 預期輸出: "This is a test"
    run_test("This is another test");    // 預期輸出: "This is rehtona test"

    
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個英文句子: ";
    // 使用 getline 讀取一整行，這樣才能處理包含空格的句子
    getline(cin, user_input);
    run_test(user_input);

    cout << "\n測試結束。\n";
    return 0;
}
