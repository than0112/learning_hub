#include <iostream>
#include <string>
#include <vector>
#include <cctype> // 引入 toupper() 函式，用於轉換為大寫
using namespace std;
string abbrevName(string name)
{
    char first_initial = name[0];
    //find() 函式用來找到第一個空格的位置。
    size_t space_pos = name.find(' ');

    // 3. 取得第二個字的首字母。
    //    它就在空格的下一個位置。
    char last_initial = name[space_pos + 1];

    // 4. 組合結果字串。
    //    - toupper() 會將字元轉為大寫。
    //    - string(1, char) 是一種將單一字元轉換為字串的技巧，
    //      這樣我們才能用 '+' 來串接它們。
    string result = "";
    result += toupper(first_initial);
    result += ".";
    result += toupper(last_initial);

    return result;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param name 要測試的姓名。
 */
void run_test(const string& name) {
    cout << "輸入: \"" << name << "\" => 輸出: \"" << abbrevName(name) << "\"" << endl;
}

// --- 主程式：用來測試 abbrevName 函式 ---
int main() {
    cout << "--- 姓名縮寫測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("Sam Harris");
    run_test("patrick feeney");

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個包含姓和名的英文名字: ";
    getline(cin, user_input);
    run_test(user_input);

    cout << "\n測試結束。\n";
    return 0;
}
