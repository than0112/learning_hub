#include <iostream>
#include <string>
#include <algorithm>

using namespace std; // 使用 std 命名空間

// 判斷是否為迴文的函式
bool isPalindrome(const string& s) {
    if (s.empty()) {
        return true;
    }
    // 不再需要寫 std::equal
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

int main() {
    string userInput;
    cout << "請輸入一個字串："; // 不再需要寫 std::cout
    cin >> userInput;           // 不再需要寫 std::cin

    if (isPalindrome(userInput)) {
        cout << "'" << userInput << "' 是一個迴文。" << endl; // 不再需要寫 std::endl
    } else {
        cout << "'" << userInput << "' 不是一個迴文。" << endl;
    }

    return 0;
}