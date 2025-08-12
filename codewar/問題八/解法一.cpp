#include <iostream>
#include <string>

using namespace std;

string get_middle(const string& str) {
    // 1. 取得字串的總長度。
    int length = str.length();

    int middle_index = length / 2;

    // 3. 判斷字串長度的奇偶性。
    // 我們使用模數運算子 (%)，如果 length % 2 不等於 0，代表是奇數。
    if (length % 2 != 0) {
        // 長度為奇數 (例如 "testing", length=7, middle_index=3)
        // 我們從中間索引開始，取 1 個字元。
        return str.substr(middle_index, 1);
    } else {
        // 長度為偶數 (例如 "test", length=4, middle_index=2)
        // 從中間索引的前一個位置開始，取 2 個字元。
        return str.substr(middle_index - 1, 2);
    }
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
