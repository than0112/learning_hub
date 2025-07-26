#include <iostream>
#include <vector>

using namespace std;

// 輔助函式，用來印出 vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50};
    
    cout << "原始陣列: ";
    printVector(numbers);

    if (!numbers.empty()) {
        // --- 核心邏輯 ---
        // 迴圈從第一個元素開始，遍歷到倒數第二個元素
        for (size_t i = 0; i < numbers.size() - 1; i++) {
            // 將後一個元素的值，複製到前一個元素的位置上
            numbers[i] = numbers[i + 1];
        }
        // 將最後一個元素設為 0
        numbers.back() = 0; 
    }

    cout << "簡單左移後: ";
    printVector(numbers);

    return 0;
}
/*
!numbers.empty()

這句話的字面翻譯就是：「『這個陣列是空的嗎？』這個問題的相反答案」。

讓我們再看一次表格：

vector 的狀態	numbers.empty()	!numbers.empty() (整個條件的最終結果)
{} (空的)	       true	             !true → false
{10, 20}          (非空)false	         !false → true

匯出到試算表
所以，if (!numbers.empty()) 就等同於在說：「如果 numbers 裡面至少有一個元素，那麼就執行接下來的程式碼。」

*/