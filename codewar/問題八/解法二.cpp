#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 取得一個字串的中間字元 (精簡數學法)。
 * @details 此方法透過巧妙的整數除法，統一處理了奇數和偶數長度的情況，
 * 無需使用 if-else 判斷式。
 * @param str 輸入的字串 (長度 >= 1)。
 * @return string 中間的字元(或字元們)。
 */
string get_middle(const string& str) {
    // 1. 取得字串長度。
    // size_t 是一種常用於表示大小或索引的無號整數型別。
    size_t size = str.size();

    // 2. 計算起始索引 (begin)。
    // 數學原理：
    // - 如果長度是奇數 (例如 7)，(7-1)/2 = 3。起始索引就是 3。
    // - 如果長度是偶數 (例如 6)，(6-1)/2 = 2。起始索引就是 2。
    size_t begin = (size - 1) / 2;

    // 3. 計算要提取的長度 (length)。
    // 數學原理：
    // - 如果長度是奇數 (例如 7)，2 - (7 % 2) = 2 - 1 = 1。長度為 1。
    // - 如果長度是偶數 (例如 6)，2 - (6 % 2) = 2 - 0 = 2。長度為 2。
    size_t length = 2 - (size % 2);

    // 4. 使用 substr 提取子字串並回傳。
    return str.substr(begin, length);
}

// --- 主程式：用來測試 get_middle 函式 ---
int main() {
    cout << "--- 取得中間字元測試器 ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](const string& input) {
        cout << "輸入: \"" << input << "\" --> 輸出: \"" << get_middle(input) << "\"" << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("test");    // 預期輸出: "es"
    run_test("testing"); // 預期輸出: "t"
    run_test("middle");  // 預期輸出: "dd"
    run_test("A");       // 預期輸出: "A"
    
    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個您想測試的字串: ";
    getline(cin, user_input);
    run_test(user_input);

    cout << "\n測試結束。\n";
    return 0;
}
