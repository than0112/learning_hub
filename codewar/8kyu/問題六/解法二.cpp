#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

bool XO(const string& str)
{
	int counter = 0;
	// 遍歷字串中的每一個字元
	for (char c : str)
	{
		// 遇到 'x' 或 'X'，計數器加一
		if (c == 'x' || c == 'X')
			counter++;

		// 遇到 'o' 或 'O'，計數器減一
		if (c == 'o' || c == 'O')
			counter--;
	}
	// 如果計數器最終為 0，代表 'x' 和 'o' 的數量相等
	return counter == 0;
}

int main() {
    cout << "--- XO 數量測試器 (單一計數器法) ---\n";

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
