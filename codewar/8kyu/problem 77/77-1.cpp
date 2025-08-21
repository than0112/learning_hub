/*Given a month as an integer from 1 to 12, 
return to which quarter of the year it belongs as an integer number.
For example: month 2 (February), is part of the first quarter; 
month 6 (June), is part of the second quarter; 
and month 11 (November), is part of the fourth quarter.
Constraint:1 <= month <= 12
我這個題目我將兩個寫法合併再一起
*/
#include <iostream>
#include <string>
#include <limits> // 用於暫停功能
using namespace std;
int quarter_of_math(int month) {
  
    return (month - 1) / 3 + 1;
}
int quarter_of_switch(int month) {
  
    switch (month) {
        case 1:
        case 2:
        case 3:
            return 1; // 1-3 月是第一季度
        case 4:
        case 5:
        case 6:
            return 2; // 4-6 月是第二季度
        case 7:
        case 8:
        case 9:
            return 3; // 7-9 月是第三季度
        case 10:
        case 11:
        case 12:
            return 4; // 10-12 月是第四季度
        default:
            return 0;
    }
}

void run_test(int m) {
    cout << "輸入: " << m << " 月" << endl;
    cout << "  -> 數學法輸出: 第 " << quarter_of_math(m) << " 季度" << endl;
    cout << "  -> Switch法輸出: 第 " << quarter_of_switch(m) << " 季度" << endl;
}

// --- 主程式：用來測試 quarter_of 函式 ---
int main() {
    cout << "--- 年度季度計算器 ---\n";

    // --- 執行範例測試 ---
    cout << "\n--- 範例測試 ---\n";
    run_test(2);
    run_test(6);
    run_test(11);
    run_test(3);
    run_test(8);

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個您想測試的月份 (1-12) (輸入非數字結束): ";
    while (cin >> user_input) {
        if (user_input >= 1 && user_input <= 12) {
            run_test(user_input);
        } else {
            cout << "請輸入 1 到 12 之間的數字。\n";
        }
        cout << "\n請輸入下一個要測試的月份 (輸入非數字結束): ";
    }

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
