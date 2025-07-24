#include <iostream>

using namespace std;

// 輔助函式：計算一個數字的各位數之和
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    const int limit = 1000;
    cout << "在 1 到 " << limit << " 之間的哈沙德數有：" << endl;

    // 遍歷 1 到 1000 的所有數字
    for (int i = 1; i <= limit; ++i) {
        
        // 計算 i 的各位數之和
        int digit_sum = sumOfDigits(i);

        // 檢查 i 是否能被它的各位數之和整除
        if (i % digit_sum == 0) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}