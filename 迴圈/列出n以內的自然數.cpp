#include <iostream>

using namespace std;

int main() {
    int n,i,j;

    cout << "請輸入一個正整數的上限 n: ";
    cin >> n;

    cout << "在 1 到 " << n << " 的範圍內，找到的完全數有：" << endl;

    // 外層迴圈：檢查從 1 到 n 的每一個數字 i
    for (int i = 1; i <= n; ++i) {
        
        int sum_of_divisors = 0; // 用來累加 i 的真因數總和

        // 內層迴圈：找出 i 的所有真因數並加總
        // 檢查從 1 開始，直到 i-1 的所有數字 j
        for (int j = 1; j < i; ++j) {
            // 如果 j 能被 i 整除，代表 j 是 i 的一個因數
            if (i % j == 0) {
                sum_of_divisors += j;
            }
        }

        // 檢查真因數的總和是否等於 i 本身
        if (sum_of_divisors == i) {
            // 如果相等，就代表 i 是一個完全數，立刻印出來
            cout << i << " ";
        }
    }

    cout << endl; // 最後換行

    return 0;
}