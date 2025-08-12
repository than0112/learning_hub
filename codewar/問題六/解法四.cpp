#include <iostream>
#include <string>
#include <cctype> // 在這個版本中不是必需的，但保留是個好習慣

using namespace std;

/**
 * @brief 方法四：單一計數器與 switch 判斷式
 * @details 使用一個計數器，透過 switch 判斷式來增減計數。
 * 'o' 或 'O' 會使計數器加一，'x' 或 'X' 會使其減一。
 * @param str 輸入的字串。
 * @return bool 如果 'x' 和 'o' 的數量相等則回傳 true，否則回傳 false。
 */
bool XO(const string& str)
{
  int balance = 0;
  // 遍歷字串中的每一個字元
  for (char c : str) {
    // switch 判斷式會檢查字元 c 的值
    switch (c) {
       // 如果 c 是 'o' 或 'O'，就執行這裡
       case 'o':
       case 'O':
          ++balance; // 計數器加一
          break;     // 跳出 switch
       // 如果 c 是 'x' 或 'X'，就執行這裡
       case 'x':
       case 'X':
          --balance; // 計數器減一
          break;     // 跳出 switch
       // 如果 c 是其他任何字元，就執行 default
       default:
          break;     // 不做任何事，直接跳出
    }
  }
  // 如果計數器最終為 0，代表兩者數量相等
  return balance == 0;
}


// --- 主函式，用來測試 XO 函式 ---
int main() {
    cout << "--- XO 數量測試器 (switch 計數法) ---\n";

    // 一個輔助的 lambda 函式，讓測試流程更簡潔
    auto run_test = [](const string& input) {
        cout << "輸入: \"" << input << "\" => 輸出: " 
             << (XO(input) ? "true" : "false") << endl;
    };

    // --- 執行範例測試案例 ---
    cout << "\n--- 範例測試案例 ---\n";
    run_test("ooxx");
    run_test("xooxx");
    run_test("ooxXm");
    run_test("zpzpzpp");
    run_test("zzoo");

    // --- 自訂測試 ---
    cout << "\n--- 自訂測試 ---\n";
    string user_input;
    cout << "請輸入一個要測試的字串: ";
    getline(cin, user_input);
    run_test(user_input);

    cout << "\n測試完成。\n";
    return 0;
}
