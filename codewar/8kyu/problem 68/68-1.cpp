#include <iostream>
#include <string>
#include <algorithm> // 引入 sort 函式
#include <vector>    
#include <cinttypes> // 引入 cinttypes 以使用 uint64_t
#include <limits>    // 用於暫停功能

using namespace std;
uint64_t descendingOrder(uint64_t a)
{
    // 1. 將數字轉換為字串，方便我們處理每一位數。
    string s = to_string(a);

    // 2. 對字串進行降序排序。
    //    - sort(s.rbegin(), s.rend()) 是一個巧妙的技巧。
    //    - s.rbegin() 和 s.rend() 是「反向迭代器」，分別指向字串的結尾和開頭。
    //    - 對反向的序列進行「升序」排序，效果就等同於對原始序列進行「降序」排序。
    sort(s.rbegin(), s.rend());

    // 3. 將排序好的字串轉換回 unsigned long long 型別的數字並回傳。
    //    stoull 是 "string to unsigned long long" 的縮寫。
    return stoull(s);
}
void run_test(uint64_t number) {
    cout << "輸入: " << number << " -> 輸出: " << descendingOrder(number) << endl;
}

// --- 主程式：用來測試 descendingOrder 函式 ---
int main() {
    cout << "--- 數字降序排列測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(42145);
    run_test(145263);
    run_test(123456789);

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    uint64_t user_input;
    cout << "請輸入一個您想測試的非負整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的非負整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
