#include <iostream>
#include <vector>

// 使用 std 命名空間
using namespace std;

// --- 函式原型宣告 ---
long long fibonacci_recursive(int n);
long long fibonacci_iterative(int n);


int main() {
    int n;
    cout << "你想計算費氏數列的第幾項？ 請輸入一個正整數 n: ";
    cin >> n;

    if (n <= 0) {
        cout << "請輸入大於 0 的整數。" << endl;
        return 1;
    }

    cout << "\n正在使用兩種方法計算中...\n" << endl;

    // --- 方法一：迭代法 (推薦使用) ---
    cout << "方法 1 (迭代法):" << endl;
    long long result_iterative = fibonacci_iterative(n);
    cout << "  費氏數列的第 " << n << " 項是: " << result_iterative << endl;


    // --- 方法二：遞迴法 (僅供教學，效能較差) ---
    // 當 n > 40 時，遞迴會非常慢，這裡加一個提示
    if (n > 40) {
        cout << "\n方法 2 (遞迴法):" << endl;
        cout << "  警告：當 n > 40 時，遞迴法會非常慢，請耐心等候..." << endl;
    } else {
        cout << "\n方法 2 (遞迴法):" << endl;
    }
    long long result_recursive = fibonacci_recursive(n);
    cout << "  費氏數列的第 " << n << " 項是: " << result_recursive << endl;


    return 0;
}
long long fibonacci_iterative(int n) {
    // 基本情況：如果 n 是 1 或 2，直接回傳 1
    if (n <= 2) {
        return 1;
    }

    long long a = 1; // 代表 F(n-2)
    long long b = 1; // 代表 F(n-1)
    long long current; // 代表 F(n)

    // 從第 3 項開始循環計算
    for (int i = 3; i <= n; ++i) {
        current = a + b; // 計算當前項
        a = b;           // 向前滾動：將舊的 F(n-1) 變成新的 F(n-2)
        b = current;     // 向前滾動：將當前項變成新的 F(n-1)
    }

    return current;
}
long long fibonacci_recursive(int n) {
    // 基本情況 (Base Case):
    // 第 1 項和第 2 項都是 1，這是遞迴的終點。
    if (n <= 2) {
        return 1;
    }
    // 遞迴關係 (Recursive Step):
    // 第 n 項的值等於 (n-1)項 + (n-2)項。
    // 函數呼叫自己來解決規模更小的問題。
    else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}