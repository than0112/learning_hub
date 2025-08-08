#include <iostream>
#include <string>
#include <set>       // 使用 set 來建立高效的查詢表
#include <limits>    // 用於處理無效輸入

// 使用 std 命名空間
using namespace std;

/**
 * @brief 使用高效的查表法，判斷一個數是否為水仙花數。
 * @param value 要檢查的正整數。
 * @note 演算法策略:
 * 此函式採用預先計算的集合進行高效查詢。它將所有在 C++ int 
 * 型別範圍內的已知水仙花數儲存在一個靜態集合 (static set) 中。
 * `static` 關鍵字確保這個集合只會在程式首次執行時初始化一次，
 * 之後的呼叫都會共用同一個集合，效能極高。
 * @warning **重要限制**:
 * 此函式僅對標準的 `int` 型別有效。請勿用於 `long long` 或其他
 * 更大範圍的整數，因為預計算列表並未涵蓋這些範圍。
 * @return bool 如果是水仙花數則回傳 true，否則回傳 false。
 */
bool isNarcissistic(const int value) {
    // 防護機制：根據數學定義，水仙花數為正整數。
    if (value <= 0) {
        return false;
    }

    // 使用 static const 確保集合只在程式首次執行時初始化一次。
    static const set<int> narcissistic_numbers = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474,
        54748, 92727, 93084, 548834, 1741725, 4210818, 9800817, 9926315,
        24678050, 24678051, 88593477, 146511208, 472335975, 534494836, 912985153
    };

    // 使用 .count() 方法來檢查 value 是否存在於集合中。
    // .count() 對於 set 來說，只會回傳 0 (不存在) 或 1 (存在)，非常適合用於判斷。
    return narcissistic_numbers.count(value);
}

// --- 主程式：展示查表法的應用 ---
int main() {
    cout << "====================================\n";
    cout << "   水仙花數判斷器 (高效查表版)\n";
    cout << "====================================\n";

    // --- 測試幾個預設的範例 ---
    cout << "\n--- 預設範例測試 ---\n";
    int test_cases[] = {153, 1652, 9, 912985153};
    for (int number : test_cases) {
        cout << "數字 " << number << (isNarcissistic(number) ? " 是 " : " 不是 ") << "水仙花數。\n";
    }

    // --- 讓使用者自行輸入測試 ---
    cout << "\n--- 手動測試 ---\n";
    int user_input;
    cout << "請輸入一個您想測試的正整數 (輸入0結束): ";
    
    while ((cin >> user_input) && user_input != 0) {
        if (cin.fail() || user_input < 0) {
            cout << "[錯誤] 請輸入有效的正整數。\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
             cout << "結果: " << user_input << (isNarcissistic(user_input) ? " 是 " : " 不是 ") << "水仙花數。\n";
        }
        cout << "\n請輸入下一個要測試的正整數 (輸入0結束): ";
    }

    cout << "\n感謝使用，程式結束。\n";
    return 0;
}
