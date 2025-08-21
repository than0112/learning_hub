#include <iostream>
#include <string>
#include <vector>
#include <limits>    // 用於暫停功能

using namespace std;
int string_to_number(const std::string& s) {
 
  // stoi 是 "string to integer" 的縮寫，
  // 專門用來將字串轉換為整數的標準函式，能夠正確處理正數、負數和 0。
  return std::stoi(s);
}


void run_test(const string& str) {
    cout << "輸入: \"" << str << "\" --> 輸出: " << string_to_number(str) << endl;
}

// --- 主程式：用來測試 string_to_number 函式 ---
int main() {
    cout << "--- 字串轉數字測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("1234");
    run_test("605");
    run_test("1405");
    run_test("-7");

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
