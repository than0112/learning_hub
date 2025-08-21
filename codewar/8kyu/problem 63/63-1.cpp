#include <iostream>
#include <string>
#include <vector>
#include <sstream>   // 引入 stringstream
#include <algorithm> // 引入 reverse 函式
#include <limits>    // 用於暫停功能

using namespace std;
std::string reverse_words(const std::string& str) {
    // --- 演算法邏輯 ---

    // 1. 使用 stringstream 來拆解輸入的句子為一個個單字。
    stringstream ss(str);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    // 2. 使用reverse 演算法，直接將整個單字列表的順序反轉。
    reverse(words.begin(), words.end());

    // 3. 將反轉後的單字列表重新組合成一個句子。
    if (words.empty()) {
        return "";
    }
    
    string result = words[0];
    for (size_t i = 1; i < words.size(); ++i) {
        result += " " + words[i];
    }

    return result;
}

void run_test(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: \"" << reverse_words(input) << "\"" << endl;
}

// --- 主程式：用來測試 reverse_words 函式 ---
int main() {
    cout << "--- 單字反轉測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("The greatest victory is that which requires no battle");
    
    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test("hello world");
    run_test("a b c d e");

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
