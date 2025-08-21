#include <iostream>
#include <vector>
#include <limits> // 用於暫停功能
#include <iomanip> // 用於 std::setprecision
#include <numeric>
using namespace std;

double sum (const vector<double>& numbers) {
    
    return accumulate(numbers.begin(), numbers.end(), 0.0);
}
void run_test(const vector<double>& numbers) {
    cout << "輸入: ";
     for(size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << (i < numbers.size() - 1 ? ", " : "");
    }
    cout << "] -> 輸出: " << sum(numbers) << endl;
}
int main() {
    cout << "--- 簡單加總測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({1, 2, 3, 4, 5}); // 預期輸出: 15
    run_test({10, 20, 30});     // 預期輸出: 60
    run_test({-1, -2, -3});     // 預期輸出: -6

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test({0});              // 預期輸出: 0
    run_test({1.5, 2.5});       // 預期輸出: 4.0

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略輸入緩衝區中的所有內容
    cin.get(); // 等待使用者按下 Enter 鍵

    return 0;
}