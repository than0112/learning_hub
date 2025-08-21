#include <iostream>
#include <string>
#include <limits> // 用於暫停功能
using namespace std;
string fakeBin(string str) {
    // --- 演算法邏輯 ---
    // 我們使用 for-each 迴圈來遍歷字串中的每一個字元。
    // char& c 中的 '&' 代表「參考」，讓我們可以直接修改字串中的字元。
    for (char &c : str) {
        // 使用三元運算子進行判斷和替換：
        // 如果字元 c 小於 '5'，就將它替換為 '0'。
        // 否則，就將它替換為 '1'。
       
        c = (c < '5') ? '0' : '1';
    }
    // 回傳已經被完整修改過的字串。
    return str;
}

void run_test(const string& input) {
    cout << "輸入: \"" << input << "\" -> 輸出: \"" << fakeBin(input) << "\"" << endl;
}

// --- 主程式：用來測試 fakeBin 函式 ---
int main() {
    cout << "--- 偽二進位轉換器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("45385593107843568");
    run_test("509321967506747");
    run_test("366058562030849490134388085");

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一串您想轉換的數字 (輸入 'q' 結束): ";
    while (cin >> user_input && user_input != "q") {
        run_test(user_input);
        cout << "\n請繼續輸入 (輸入 'q' 結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
