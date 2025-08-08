#include <iostream>
#include <string>
#include <cctype> // 引入 tolower() 函式

using namespace std;

/**
 * @brief 檢查一個字串是否包含相同數量的 'x' 和 'o' (不區分大小寫)。
 * @param str 輸入的字串，可包含任意字元。
 * @return bool 如果 'x' 和 'o' 的數量相等則回傳 true，否則回傳 false。
 */
bool XO(const string& str)
{
    int x_count = 0;
    int o_count = 0;

    // 2. 遍歷輸入字串中的每一個字元。
    // for-each 迴圈是一種簡潔的遍歷方式。
    for (char c : str) {
        
        // 3. 為了處理不區分大小寫，將當前字元轉換為小寫。
        char lower_c = tolower(c);

        // 4. 檢查小寫字元並更新對應的計數器。
        if (lower_c == 'x') {
            x_count++;
        } else if (lower_c == 'o') {
            o_count++;
        }
    }

    // 5. 比較最終的計數結果。
    // 這個比較運算式 (x_count == o_count) 的結果本身就是 true 或 false，可以直接回傳。
    return x_count == o_count;
}

int main() {
    cout << "--- XO 數量測試器 ---\n";

    // 一個輔助的 lambda 函式，讓測試流程更簡潔
    auto run_test = [](const string& input) {
        cout << "輸入: \"" << input << "\" => 輸出: " 
             << (XO(input) ? "true" : "false") << endl;
    };

    // --- 執行範例測試案例 ---
    cout << "\n--- 範例測試案例 ---\n";
    run_test("ooxx");    // 預期: true
    run_test("xooxx");   // 預期: false
    run_test("ooxXm");   // 預期: true
    run_test("zpzpzpp"); // 預期: true (0 個 x, 0 個 o)
    run_test("zzoo");    // 預期: false

    // --- 自訂測試 ---
    cout << "\n--- 自訂測試 ---\n";
    string user_input;
    cout << "請輸入一個要測試的字串: ";
    getline(cin, user_input);
    run_test(user_input);

    cout << "\n測試完成。\n";
    return 0;
}
