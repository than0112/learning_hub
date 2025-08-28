#include <iostream>
#include <string>
#include <vector>
#include <cctype>   
#include <limits>   
using namespace std;
bool isOpposite(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length() || (s1.empty() && s2.empty())) {
        return false;
    }
    for (size_t i = 0; i < s1.length(); ++i) {
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 == c2 || tolower(c1) != tolower(c2)) {
            return false;
        }
    }

    return true;
}
void run_test(const string& str1, const string& str2) {
    cout << "輸入: (\"" << str1 << "\", \"" << str2 << "\")"
         << " -> 輸出: " << (isOpposite(str1, str2) ? "true" : "false") << endl;
}

int main() {
    cout << "--- 大小寫相反字串測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("ab", "AB");
    run_test("aB", "Ab");
    run_test("aBcd", "AbCD");
    run_test("AB", "Ab");
    run_test("", "");

    run_test("Hello", "hELLO");
    run_test("abc", "abC");

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
