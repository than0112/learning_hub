#include <iostream>
#include <cctype> // 必須引用 cctype 標頭檔

// 使用 std 命名空間
using namespace std;

int main() {
    char lower_a = 'a';
    char upper_B = 'B';
    char symbol = '?';

    // 將小寫 'a' 轉成大寫 'A'
    char result1 = toupper(lower_a);
    cout << "'" << lower_a << "' 轉換後是 '" << result1 << "'" << endl;

    // 'B' 已經是大寫，所以不變
    char result2 = toupper(upper_B);
    cout << "'" << upper_B << "' 轉換後是 '" << result2 << "'" << endl;

    // '?' 不是字母，所以也不變
    char result3 = toupper(symbol);
    cout << "'" << symbol << "' 轉換後是 '" << result3 << "'" << endl;

    return 0;
}