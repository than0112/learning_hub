/*Create a function that finds the integral of the expression passed.

In order to find the integral all you need to do is add one to the exponent (the second argument), and divide the coefficient (the first argument) by that new number.

For example for 3x^2, the integral would be 1x^3: we added 1 to the exponent, and divided the coefficient by that new number).

Notes:

The output should be a string.
The coefficient and exponent is always a positive integer.
Examples
 3, 2  -->  "1x^3"
12, 5  -->  "2x^6"
20, 1  -->  "10x^2"
40, 3  -->  "10x^4"
90, 2  -->  "30x^3"*/
#include <iostream>
#include <string>
#include <limits>    // 用於暫停功能
using namespace std;
std::string integrate(const int& coefficient, const int& exponent) {
    // 1. 計算新的指數。
    //    積分法則：新指數 = 原指數 + 1
    int new_exponent = exponent + 1;

    // 2. 計算新的係數。
    //    積分法則：新係數 = 原係數 / 新指數
    int new_coefficient = coefficient / new_exponent;

    // 3. 使用 to_string 將數字轉換為字串，並組合出最終的格式。
    return to_string(new_coefficient) + "x^" + to_string(new_exponent);
}

void run_test(int c, int e) {
    cout << "輸入: (" << c << ", " << e << ")  -->  輸出: \"" 
         << integrate(c, e) << "\"" << endl;
}

// --- 主程式：用來測試 integrate 函式 ---
int main() {
    cout << "--- 積分計算器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test(3, 2);
    run_test(12, 5);
    run_test(20, 1);
    run_test(40, 3);
    run_test(90, 2);

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
