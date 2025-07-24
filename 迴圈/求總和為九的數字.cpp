#include <iostream>

using namespace std;

// 一個輔助函式，專門用來計算一個數字的各位數之和
int sumOfDigits(int n) {
    int sum = 0;
    // 使用我們熟悉的 % 和 / 運算來拆解數字
    while (n > 0) {
        sum += n % 10; // 加上個位數
        n /= 10;      // 移除個位數
    }
    return sum;
}

int main() {
    const int limit = 1000;
    const int target_sum = 9;

    cout << "所有小於 " << limit << " 且各位數之和等於 " << target_sum << " 的數值有：" << endl;

    // 迴圈遍歷從 1 到 999 的所有數字
    for (int i = 1; i < limit; ++i) {
        // 呼叫函式計算 i 的各位數之和
        if (sumOfDigits(i) == target_sum) {
            // 如果和等於目標值，就印出 i
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}