#include <iostream>
#include <string>
#include <cctype>

// 使用 std 命名空間
using namespace std;

int main() {
    string greeting = "Hello, World!";
    cout << "原始字串: " << greeting << endl;

    // 使用 for 迴圈遍歷字串中的每一個字元
    // 注意這裡用 char &c (傳參考)，這樣才能直接修改原始字串
    for (char &c : greeting) {
        c = toupper(c); // 將每個字元轉為大寫再存回去
    }

    cout << "轉換後字串: " << greeting << endl;

    return 0;
}