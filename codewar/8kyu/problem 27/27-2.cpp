#include <iostream>
#include <string>
#include <vector>
#include <cctype> // 引入 toupper() 函式，用於轉換為大寫
using namespace std;
string abbrevName(string name)
{
  // 1. 建立一個空字串 ret，用來存放最終結果。
  string ret;
  
  // 2. 將名字的第一個字母轉為大寫後，加入到 ret 的尾端。
  ret.push_back(toupper(name[0]));
  
  // 3. 加入一個點 '.' 到 ret 的尾端。
  ret.push_back('.');
  
  // 4. 找到姓氏的第一個字母，轉為大寫後，加入到 ret 的尾端。
  //    - name.find(' ') 會找到空格的索引。
  //    - + 1 則是指向空格後面的那個字元，也就是姓氏的首字母。
  ret.push_back(toupper(name[name.find(' ') + 1] ));
  
  // 5. 回傳建立好的縮寫。
  return ret;
}

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
