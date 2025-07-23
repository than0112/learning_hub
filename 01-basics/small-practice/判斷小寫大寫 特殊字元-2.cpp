#include <iostream>
#include <cctype> // 引入 cctype 函式庫，用來處理字元分類

using namespace std;

int main() {
    char input_char;

    cout << "請輸入一個字元：";
    cin >> input_char;
    // 使用 if-else if-else 結構來進行判斷
    if (input_char >= 'a' && input_char <= 'z') {
    cout << "小寫字母" << endl;
}
else if (input_char >= 'A' && input_char <= 'Z') {
    cout << "大寫字母" << endl;
}
else if (input_char >= '0' && input_char <= '9') {
    cout << "數字" << endl;
}
else {
    cout << "特殊字元" << endl;
}
    

    return 0;
}
