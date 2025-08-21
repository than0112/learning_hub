#include <iostream>
#include <string>
#include <algorithm> // 引入 reverse 函式
#include <limits>    // 用於暫停功能
using namespace std;
string reverseString(const string &str)
{
    return string(str.rbegin(), str.rend());
}
void run_test(const string& input) {
    cout << "輸入: '" << input << "'  =>  輸出: '" << reverseString(input) << "'" << endl;
}
int main() {
    cout << "--- 字串反轉測試器 ---\n";
    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("world");
    run_test("word");
    cout << "\n--- 手動測試 ---\n";
    string user_input;
    cout << "請輸入一個您想反轉的字串: ";
    getline(cin, user_input);
    run_test(user_input);

    cout << "\n測試結束。\n";
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
