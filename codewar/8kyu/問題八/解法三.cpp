#include <iostream>
#include <string>

using namespace std;
string get_middle(string input) 
{
    size_t size = input.size();
    
    // 檢查字串長度是偶數還是奇數
    if (size % 2 == 0)
    {
        // 長度為偶數的情況
        // 例如 "middle" (長度 6)，中間索引是 (6/2)-1 = 2
        // 從索引 2 開始，取 2 個字元 ("dd")
        size_t index = (size / 2) - 1;
        return input.substr(index, 2);
    }
    else
    {
        // 長度為奇數的情況
        // 例如 "testing" (長度 7)，中間索引是 (7-1)/2 = 3
        // 從索引 3 開始，取 1 個字元 ("t")
        size_t index = (size - 1) / 2;
        return input.substr(index, 1);
    } 
}

// --- 主程式：用來測試 get_middle 函式 ---
int main() {
    cout << "--- 取得中間字元測試器 (if-else 法) ---\n";

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
