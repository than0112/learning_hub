#include <iostream>
#include <string>
#include <stdexcept> // 引入 stdexcept，才能使用 invalid_argument 例外
#include <limits>    // 用於暫停功能

using namespace std;
double calculator(double a, double b, char op) {
    // 使用 switch 判斷式來處理不同的運算符號
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            // 處理除以零的特殊情況
            if (b == 0) {
                // 拋出一個例外，並附上錯誤訊息
                throw invalid_argument("Error: Division by zero is not allowed.");
            }
            return a / b;
        default:
            // 如果 op 不是以上任何一種，就拋出例外
            throw invalid_argument("Error: Invalid operator provided.");
    }
}


void run_test(double a, double b, char op) {
    cout << "輸入: " << a << ", " << b << ", '" << op << "' -> ";
    // 使用 try-catch 區塊來「捕捉」可能從 calculator 函式拋出的例外
    try {
        double result = calculator(a, b, op);
        cout << "輸出: " << result << endl;
    } catch (const invalid_argument& e) {
        // 如果捕捉到例外，就印出例外物件中的錯誤訊息
        cout << "錯誤: " << e.what() << endl;
    }
}

// --- 主程式：用來測試 calculator 函式 ---
int main() {
    cout << "--- 簡單計算機測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(1, 2, '+'); // 預期輸出: 3
    run_test(10, 5, '-'); // 預期輸出: 5
    run_test(4, 5, '*'); // 預期輸出: 20
    run_test(10, 2, '/'); // 預期輸出: 5
    run_test(1, 2, '&'); // 預期輸出: 錯誤訊息
    run_test(10, 0, '/'); // 預期輸出: 錯誤訊息

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
