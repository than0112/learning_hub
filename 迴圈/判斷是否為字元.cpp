#include <iostream>

using namespace std;

int main() {
    char input_char;

    cout << "請輸入一個英文字元: ";
    cin >> input_char;

    // 使用 switch 結構來判斷
    switch (input_char) {
        // 將所有母音的情況都列出來
        // 因為 case 後面沒有 break，所以會產生「穿透 (fall-through)」效果
        // 無論符合哪一個母音，最終都會執行同一段程式碼
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            cout << "'" << input_char << "' 是一個母音。" << endl;
            break; // 判斷完畢，跳出 switch
        default:
            // 如果輸入的字元不符合上面任何一個 case，就會執行 default
            cout << "'" << input_char << "' 不是一個母音。" << endl;
            break;
    }

    return 0;
}