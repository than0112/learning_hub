#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- 主程式：所有邏輯都在這裡 ---
int main() {
    cout << "--- 尋找消失的字母測試器 (無函式版) ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";

    // --- 測試案例 1 ---
    vector<char> test1 = {'a','b','c','d','f'};
    cout << "輸入: { ";
    for(size_t i = 0; i < test1.size(); ++i) {
        cout << "'" << test1[i] << "'";
        if (i < test1.size() - 1) cout << ", ";
    }
    // 核心邏輯開始
    char missing_letter1 = test1.front();
    for(char c : test1) {
        if(c != missing_letter1) break;
        ++missing_letter1;
    }
    // 核心邏輯結束
    cout << " } -> 輸出: '" << missing_letter1 << "'" << endl;

    // --- 測試案例 2 ---
    vector<char> test2 = {'O','Q','R','S'};
    cout << "輸入: { ";
    for(size_t i = 0; i < test2.size(); ++i) {
        cout << "'" << test2[i] << "'";
        if (i < test2.size() - 1) cout << ", ";
    }
    // 核心邏輯開始
    char missing_letter2 = test2.front();
    for(char c : test2) {
        if(c != missing_letter2) break;
        ++missing_letter2;
    }
    // 核心邏輯結束
    cout << " } -> 輸出: '" << missing_letter2 << "'" << endl;


    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    
    // --- 測試案例 3 ---
    vector<char> test3 = {'X', 'Z'};
    cout << "輸入: { ";
    for(size_t i = 0; i < test3.size(); ++i) {
        cout << "'" << test3[i] << "'";
        if (i < test3.size() - 1) cout << ", ";
    }
    // 核心邏輯開始
    char missing_letter3 = test3.front();
    for(char c : test3) {
        if(c != missing_letter3) break;
        ++missing_letter3;
    }
    // 核心邏輯結束
    cout << " } -> 輸出: '" << missing_letter3 << "'" << endl;


    cout << "\n測試結束。\n";
    return 0;
}
