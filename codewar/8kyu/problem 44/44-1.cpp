#include <iostream>
#include <string>
#include <limits>    // 用於暫停功能
using namespace std;
/**
 * @brief 校正一個因文字辨識錯誤而產生的字串。
 * @details 規則：'5' -> 'S', '0' -> 'O', '1' -> 'I'
 * @param str 包含錯誤字元的原始字串。
 * @return string 校正後的新字串。
 */
string correct(string str) {
    // --- 演算法邏輯 ---
    // 我們使用 for-each 迴圈來遍歷字串中的每一個字元。
    // char& c 中的 '&' 代表「參考」，讓我們可以直接修改字串中的字元。
    for (char &c : str) {
        // 使用 switch 判斷式來檢查是否為需要校正的字元。
        switch (c) {
            case '5':
                c = 'S'; // 如果是 '5'，就替換為 'S'
                break;
            case '0':
                c = 'O'; // 如果是 '0'，就替換為 'O'
                break;
            case '1':
                c = 'I'; // 如果是 '1'，就替換為 'I'
                break;
            default:
                // 如果是其他字元，則不做任何事
                break;
        }
    }
    // 回傳已經被完整修改過的字串。
    return str;
}
void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: \"" << correct(input) << "\"" << endl;
}

// --- 主程式：用來測試 correct 函式 ---
int main() {
    cout << "--- 文字辨識校正器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("L0ND0N");      // 預期輸出: "LONDON"
    run_test("DUBL1N");      // 預期輸出: "DUBLIN"
    run_test("51NGAP0RE");   // 預期輸出: "SINGAPORE"
    run_test("BUDAPE5T");   // 預期輸出: "BUDAPEST"
    run_test("PAR15");       // 預期輸出: "PARIS"

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
