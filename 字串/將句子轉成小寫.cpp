#include <iostream>
#include <cctype>

// 使用 std 命名空間
using namespace std;

int main() {
    char upper_X = 'X';
    char lower_y = 'y';
    char number = '5';

    // 將大寫 'X' 轉成小寫 'x'
    char result1 = tolower(upper_X);
    cout << "'" << upper_X << "' 轉換後是 '" << result1 << "'" << endl;

    // 'y' 已經是小寫，所以不變
    char result2 = tolower(lower_y);
    cout << "'" << lower_y << "' 轉換後是 '" << result2 << "'" << endl;

    // '5' 不是字母，所以也不變
    char result3 = tolower(number);
    cout << "'" << number << "' 轉換後是 '" << result3 << "'" << endl;

    return 0;
}