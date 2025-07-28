//找出一串整數中的最大值及其出現位置
#include <iostream>

using namespace std;

int main() {
    int count;          // 用來存總共有幾個數字
    int current_number; // 用來存當前讀到的數字
    int max_value;      // 用來記錄最大值
    int max_position;   // 用來記錄最大值的位置

    cout << "請輸入數字的總個數: ";
    cin >> count;

    // 如果輸入的個數是 0 或負數，直接結束
    if (count <= 0) {
        cout << "沒有有效的數字可以比較。" << endl;
        return 0;
    }

    // 1. 先處理第一個數字
    cout << "請輸入第 1 個數字: ";
    cin >> current_number;
    max_value = current_number; // 假設第一個就是最大值
    max_position = 1;

    // 2. 從第二個數字開始，用迴圈處理剩下的
    for (int i = 2; i <= count; ++i) {
        cout << "請輸入第 " << i << " 個數字: ";
        cin >> current_number;

        // 3. 如果現在這個數字比記錄中的最大值還大
        if (current_number > max_value) {
            max_value = current_number; // 就更新最大值
            max_position = i;           // 並更新最大值的位置
        }
    }

    // 4. 迴圈結束，印出最後結果
    cout << "--------------------" << endl;
    cout << "最大值為: " << max_value << endl;
    cout << "出現位置為: " << max_position << endl;

    return 0;
}