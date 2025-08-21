#include <iostream>
#include <string>
#include <limits> // 用於暫停功能
using namespace std;
string switch_it_up(int number) {
    // 使用 switch 判斷式來處理每一個可能的數字情況。
    // switch 會直接跳到符合 number 值的那個 case。
    switch (number) {
        case 0: return "Zero";
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return ""; // 根據題目保證，不會執行到這裡，但加上是個好習慣。
    }
}

void run_test(int number) {
    cout << "輸入: " << number << " -> 輸出: \"" << switch_it_up(number) << "\"" << endl;
}

// --- 主程式：用來測試 switch_it_up 函式 ---
int main() {
    cout << "--- 數字轉英文單字測試器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(1);
    run_test(7);
    run_test(0);
    run_test(9);

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個 0-9 的數字 (輸入非數字結束): ";
    while (cin >> user_input) {
        if (user_input >= 0 && user_input <= 9) {
            run_test(user_input);
        } else {
            cout << "請輸入 0 到 9 之間的數字。\n";
        }
        cout << "\n請輸入下一個 0-9 的數字 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
