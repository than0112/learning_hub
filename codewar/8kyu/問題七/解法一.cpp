 #include<iostream>
#include <string>

using namespace std;

/**
 * @brief 計算一個正整數的「乘法持久性」。
 * @details 乘法持久性是指，將一個數字的各位數相乘，直到結果變為一個
 * 個位數為止，這個過程總共進行了幾次乘法。
 * @param n 一個正整數。
 * @return int 乘法的次數。
 */
int persistence(long long n) {
    // 1. 初始化一個計數器，用來記錄乘法的次數。
    int count = 0;

    // 2. 使用一個 while 迴圈。只要數字 n 仍然是兩位數或以上 (>= 10)，
    //    就代表我們還需要繼續進行乘法。
    while (n >= 10) {
        // a. 只要進入這個迴圈，就代表我們要進行一次新的乘法，所以計數器加一。
        count++;

        // b. 準備一個變數來儲存這一次各位數相乘的結果。
        //    初始值必須是 1，因為任何數乘以 1 都等於它自己。
        long long product = 1;
        
        // c. 使用一個內部迴圈來拆解數字 n 的每一位。
        //    我們用一個暫存變數 temp 來操作，才不會影響到外層的 n。
        long long temp = n;
        while (temp > 0) {
            // 取出最右邊的個位數 (temp % 10)，然後乘到 product 中。
            product *= (temp % 10);
            // 移除最右邊的個位數。
            temp /= 10;
        }

        // d. 當內部迴圈結束時，product 就是這一次乘法的完整結果。
        //    我們將 n 更新為這個新的 product，準備進行下一輪的 while 迴圈檢查。
        n = product;
    }

    // 3. 當 while 迴圈結束時，代表 n 已經是一個個位數了。
    //    我們回傳計數器的值，這就是總共的乘法次數。
    return count;
}

// --- 主程式：用來測試 persistence 函式 ---
int main() {
    cout << "--- 乘法持久性測試器 ---\n";

    // 使用一個 lambda 函式來簡化測試流程
    auto run_test = [](long long number) {
        cout << "輸入: " << number << " --> 輸出: " << persistence(number) << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(39);  // 預期輸出: 3
    run_test(999); // 預期輸出: 4
    run_test(4);   // 預期輸出: 0
    
    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test(27);  // 預期輸出: 2
    run_test(10);  // 預期輸出: 1

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    long long user_input;
    cout << "請輸入一個您想測試的正整數 (輸入非數字結束): ";
    while (cin >> user_input) {
        run_test(user_input);
        cout << "\n請輸入下一個要測試的正整數 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";
    return 0;
}
