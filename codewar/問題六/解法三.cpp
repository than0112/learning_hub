#include <iostream>
#include <string>
#include <algorithm> // 必須引入才能使用 std::count

using namespace std;

bool XO(const string& str)
{
  // 分別計算小寫 'x' 和大寫 'X' 的數量，然後相加。
  int xCount = count(str.begin(), str.end(), 'x') + count(str.begin(), str.end(), 'X');
  
  // 分別計算小寫 'o' 和大寫 'O' 的數量，然後相加。
  int oCount = count(str.begin(), str.end(), 'o') + count(str.begin(), str.end(), 'O');
  
  // 比較兩個總和是否相等。
  return xCount == oCount;
}


// --- 主函式，用來測試 XO 函式 ---
int main() {
    cout << "--- XO 數量測試器 (std::count 法) ---\n";

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
