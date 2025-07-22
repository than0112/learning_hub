//這次的練習是輸入秒數 自動轉換成時 分 秒的格式
#include <iostream>
using namespace std;
int main() {
    int total_seconds;
    cout << "請輸入秒數：";
    cin >> total_seconds;

    // 計算小時、分鐘和剩餘的秒數
    int hours = total_seconds / 3600; // 每小時有3600秒
    int minutes = (total_seconds /60) % 60; // 剩餘秒數除以60得到分鐘
    int seconds = total_seconds % 60; // 剩餘的秒數

    // 輸出結果
    cout << "轉換後的時間是：" << hours << " 小時 " << minutes << " 分鐘 " << seconds << " 秒" << endl;

    return 0;
}