#include <iostream>
#include <string>

// 使用 std 命名空間，後續的程式碼可以省略 std::
using namespace std;

int main() {
    // --- 1. 宣告變數 ---
    // 現在可以直接使用 string，而不是 std::string
    string user_name;
    string favorite_drink;

    // --- 2. 提示並讀取使用者輸入 ---
    // 提示使用者輸入姓名
    cout << "您好，請問您的姓名是？ ";
    // 使用 getline 讀取一整行輸入（包含空格），並存到 user_name 變數中
    getline(cin, user_name);

    // 提示使用者輸入喜歡的飲料
    cout << "那麼，您最喜歡喝的飲料是什麼呢？ ";
    // 再次使用 getline 讀取飲料名稱
    getline(cin, favorite_drink);

    // --- 3. 輸出包含客製化資訊的回應 ---
    // 為了讓輸出更美觀，先印出一個分隔線和換行
    cout << "\n--------------------" << endl;

    // 組合固定的問候語和使用者輸入的姓名
    cout << "你好，" << user_name << "！很高興認識你。" << endl;

   

    return 0; // 表示程式正常結束
}