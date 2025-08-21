#include <iostream>
#include <string>
#include <vector>
#include <sstream>   // 引入 stringstream，用於輕鬆拆解字串
#include <algorithm> // 引入 reverse 函式
#include <limits>    // 用於暫停功能

using namespace std;

/**
 * @brief 將一個句子中的所有單字順序反轉 (vector 法)。
 * @param str 原始的句子字串。
 * @return std::string 單字順序反轉後的新句子。
 */
std::string reverse_words(const std::string& str) {
    // --- 演算法邏輯：先拆解，再反轉，後組合 ---

    // 1. 拆解 (Split):
    //    使用 stringstream 將句子拆解成一個個單字，
    //    並存入一個 vector (可以想像成一個可自動變長的單字列表) 中。
    stringstream ss(str);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    // 2. 反轉 (Reverse):
    //    使用 C++ 標準函式庫中的 std::reverse 演算法，
    //    直接將整個單字列表的順序反轉。
    reverse(words.begin(), words.end());

    // 3. 組合 (Join):
    //    將反轉後的單字列表重新組合成一個句子。
    if (words.empty()) {
        return "";
    }
    
    string result = "";
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        // 只要不是最後一個單字，就在後面加上一個空格
        if (i < words.size() - 1) {
            result += " ";
        }
    }

    return result;
}

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param input 要測試的句子。
 */
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
