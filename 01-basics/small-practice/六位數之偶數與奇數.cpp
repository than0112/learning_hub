#include <iostream>
#include <cmath> // 使用 abs() 函式來取絕對值

using namespace std;

int main() {
    int number;
    cout << "請輸入一個六位數：";
    cin >> number;

    
    if (number < 100000 || number > 999999) {
        cout << "錯誤：請輸入有效的六位數。" << endl;
        return 1; // 結束程式
    }

    int odd_sum = 0;  // 奇位數的和 (第1, 3, 5位)
    int even_sum = 0; // 偶位數的和 (第2, 4, 6位)
    int position = 1; // 位置計數器，從右邊第一位開始

    int temp_number = number; // 用一個暫存變數來進行計算，保留原始輸入

    // 使用 while 迴圈逐一處理每一位數
    while (temp_number > 0) {
        // 1. 取得最右邊的個位數
        int digit = temp_number % 10;

        // 2. 判斷目前位數是奇數還是偶數
        if (position % 2 != 0) { // 如果 position 是奇數
            odd_sum += digit;
        } else { // 如果 position 是偶數
            even_sum += digit;
        }

        // 3. 移除最右邊的個位數，準備處理下一位
        temp_number /= 10;

        // 4. 將位置計數器加一
        position++;
    }

    // 計算兩者和的絕對差
    int difference = abs(odd_sum - even_sum);

    // 輸出結果
    cout << "奇位數的和: " << odd_sum << endl;
    cout << "偶位數的和: " << even_sum << endl;
    cout << "兩者之差為: " << difference << endl;

    return 0;
}