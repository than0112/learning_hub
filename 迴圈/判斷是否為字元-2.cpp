#include <iostream>
#include <cctype> // 引入 cctype 函式庫，為了使用 tolower() 和 isalpha()

using namespace std;

int main() {
    char input_char;

    cout << "請輸入一個英文字元: ";
    cin >> input_char;

    // isalpha() 檢查輸入的是否為一個英文字母
    if (isalpha(input_char)) {
        // tolower() 如果輸入的是大寫字母，將大寫字母轉成小寫，其他字元不變
        char lower_char = tolower(input_char);

        if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
            cout << "'" << input_char << "' 是一個母音。" << endl;
        } else {
            cout << "'" << input_char << "' 不是一個母音 (是子音)。" << endl;
        }
    } else {
        cout << "'" << input_char << "' 不是一個英文字母。" << endl;
    }

    return 0;
}