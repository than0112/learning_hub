#include <iostream>
#include <string>
#include <sstream> // 引入 stringstream，這是轉換的關鍵
#include <limits>  

using namespace std;
int hexToDec(string hexString)
{
    stringstream ss;

    // 2. 將十六進位的字串放入轉換器中。
    ss << hexString;

    // 3. 準備一個整數變數來接收轉換後的結果。
    int dec_value;

    // 4. 使用 stringstream 的 >> 運算子來將十六進位字串轉換為十進位整數。
    //    這裡的 hex 是一個格式標誌，告訴 stringstream 我們要處理的是十六進位數字。
    //    注意：這裡的 dec_value 會自動被轉換為十進位整數。
    //    如果 hexString 是 "1A"，那麼 dec_value 會變成 26。
    ss >> hex >> dec_value;

    // 5. 回傳轉換後的十進位數值。
    return dec_value;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param hex_str 要測試的十六進位字串。
 */
void run_test(const string& hex_str) {
    cout << "輸入: \"" << hex_str << "\" -> 輸出: " << hexToDec(hex_str) << endl;
}

// --- 主程式：用來測試 hexToDec 函式 ---
int main() {
    cout << "--- 十六進位轉十進位測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("1");    // 預期輸出: 1
    run_test("a");    // 預期輸出: 10
    run_test("10");   // 預期輸出: 16
    run_test("FF");   // 預期輸出: 255
    run_test("201");  // 預期輸出: 513

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個您想測試的十六進位字串 (輸入 'q' 結束): ";
    while (cin >> user_input && user_input != "q") {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的十六進位字串 (輸入 'q' 結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
