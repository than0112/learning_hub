#include <iostream>
#include <string>
#include <vector>
#include <cctype> // 引入 toupper() 函式，用於轉換為大寫

using namespace std;

/**
 * @brief 將一個由兩個單字組成的姓名，轉換為大寫的首字母縮寫 (鏈式修改法)。
 * @param name 包含一個空格的姓名，例如 "Sam Harris"。
 * @return std::string 格式化後的首字母縮寫，例如 "S.H"。
 */
std::string abbrevName(std::string name)
{
  // 透過一連串的 erase 和 insert 操作，直接修改 name 字串的複本。
  // 1. erase(1, name.find(' ')): 移除名字第一個字母後到姓氏前的所有字元。
  // 2. .erase(2): 移除姓氏第一個字母後的所有字元。
  // 3. .insert(1, "."): 在兩個首字母中間插入一個點。
  name.erase(1, name.find(' ')).erase(2).insert(1, ".");
  
  // 將結果字串中的所有字元轉為大寫。
  for (auto & c: name) c = toupper(c);
  
  return name;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param name 要測試的姓名。
 */
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
