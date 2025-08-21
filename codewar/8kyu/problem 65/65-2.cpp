#include <iostream>
#include <string>
#include <limits> // 用於暫停功能
using namespace std;
string greet(const string& name, const string& owner) {
    // --- 演算法邏輯 ---
    // 使用 if-else 判斷式來檢查兩個字串是否完全相等。
    if (owner == name) {
        // 如果相等，就回傳 "Hello boss"。
        return "Hello boss";
    } else {
        // 否則，就回傳 "Hello guest"。
        return "Hello guest";
    }
}

void run_test(const string& name, const string& owner) {
    cout << "輸入: (name=\"" << name << "\", owner=\"" << owner << "\") -> 輸出: \""
         << greet(name, owner) << "\"" << endl;
}

// --- 主程式：用來測試 greet 函式 ---
int main() {
    cout << "--- 個人化問候語測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test("Daniel", "Daniel"); // 預期輸出: "Hello boss"
    run_test("Greg", "Daniel");   // 預期輸出: "Hello guest"

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
