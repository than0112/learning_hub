#include <iostream>

// 使用 std 命名空間
using namespace std;

// --- 函式原型宣告 ---
long long sumToOne(int n);
unsigned long long factorial(int n);


int main() {
    int number;

    cout << "請輸入一個正整數 n: ";
    cin >> number;

    // 進行輸入驗證
    if (number < 0) {
        cout << "錯誤：請輸入非負整數。" << endl;
        return 1; // 錯誤退出
    }

    // --- 計算並輸出 1+2+...+n 的結果 ---
    long long sumResult = sumToOne(number);
    cout << "從 1 連加到 " << number << " 的總和是: " << sumResult << endl;

    // --- 計算並輸出 n! 的結果 ---
    // 階乘增長非常快，當 n > 20 時，unsigned long long 也會溢位
    if (number > 20) {
        cout << "警告：計算 " << number << "! 的結果可能會超出變數儲存範圍。" << endl;
    }
    unsigned long long factResult = factorial(number);
    cout << number << " 的階乘 (n!) 是: " << factResult << endl;

    return 0;
}


/**
 * @brief 遞迴函式 1: 計算從 1 連加到 n 的總和。
 * @param n 目標正整數。
 * @return long long 總和結果。
 */
long long sumToOne(int n) {
    // 基本情況 (Base Case):
    // 如果 n 是 1，問題已經到最小，直接回傳 1。
    if (n <= 1) {
        return n;
    }
    // 遞迴關係 (Recursive Step):
    // sum(n) 的問題可以拆解成「n 加上 sum(n-1) 的結果」。
    // 於是我們呼叫自己來解決 sum(n-1) 這個規模更小的問題。
    else {
        return n + sumToOne(n - 1);
    }
}

/**
 * @brief 遞迴函式 2: 計算 n 的階乘 (n!)。
 * @param n 目標正整數。
 * @return unsigned long long 階乘結果 (使用 unsigned long long 以儲存更大的數值)。
 */
unsigned long long factorial(int n) {
    // 基本情況 (Base Case):
    // 根據數學定義，0! 的結果是 1。這是遞迴的終點。
    if (n == 0) {
        return 1;
    }
    // 遞迴關係 (Recursive Step):
    // n! 的問題可以拆解成「n 乘以 (n-1)! 的結果」。
    // 於是我們呼叫自己來解決 (n-1)! 這個規模更小的問題。
    else {
        return n * factorial(n - 1);
    }
}
/*```

### 程式碼解說

#### `sumToOne(n)` 的運作流程 (以 `n=4` 為例)

1.  `sumToOne(4)` 被呼叫，它回傳 `4 + sumToOne(3)`
2.  `sumToOne(3)` 被呼叫，它回傳 `3 + sumToOne(2)`
3.  `sumToOne(2)` 被呼叫，它回傳 `2 + sumToOne(1)`
4.  `sumToOne(1)` 被呼叫，觸發**基本情況**，直接回傳 `1`。
5.  結果開始一層層地傳回去：
    * 第 3 步得到 `2 + 1 = 3`
    * 第 2 步得到 `3 + 3 = 6`
    * 第 1 步得到 `4 + 6 = 10`
6.  最終結果為 `10`。

#### `factorial(n)` 的運作流程 (以 `n=4` 為例)

1.  `factorial(4)` 被呼叫，它回傳 `4 * factorial(3)`
2.  `factorial(3)` 被呼叫，它回傳 `3 * factorial(2)`
3.  `factorial(2)` 被呼叫，它回傳 `2 * factorial(1)`
4.  `factorial(1)` 被呼叫，它回傳 `1 * factorial(0)`
5.  `factorial(0)` 被呼叫，觸發**基本情況**，直接回傳 `1`。
6.  結果開始一層層地傳回去：
    * 第 4 步得到 `1 * 1 = 1`
    * 第 3 步得到 `2 * 1 = 2`
    * 第 2 步得到 `3 * 2 = 6`
    * 第 1 步得到 `4 * 6 = 24`
7.  最終結果為 `24`。*/