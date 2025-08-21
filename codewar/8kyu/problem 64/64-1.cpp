#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

/**
 * @brief 將一個字串轉換為單字陣列。
 * @param s 原始字串。
 * @return std::vector<std::string> 包含所有單字的向量。
 */
vector<string> string_to_array(const string& s) {
    if (s.empty()) {
        return {""};
    }
    vector <string> result;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}
void run_test(const string& input) {
    cout << "輸入: \"" << input << "\" ==> 輸出: [";
    
    vector<string> result = string_to_array(input);
    
    for(size_t i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"" << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

// --- 主程式：用來測試 string_to_array 函式 ---
int main() {
    cout << "--- 字串轉陣列測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test("Robin Singh");
    run_test("I love arrays they are my favorite");
    
    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;

