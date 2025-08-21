#include <iostream>
#include <string>
#include <vector>
#include <sstream>   // 用於 stringstream 來輕鬆拆解字串
#include <numeric>   // 用於 accumulate
#include <algorithm> // 用於 sort

using namespace std;

// --- 輔助函式與類別定義 ---

// 計算一個數字字串的「體重」(各位數總和)
long long calculate_weight(const string& s) {
    long long weight = 0;
    for (char c : s) {
        weight += (c - '0'); // 將字元轉為數字並累加
    }
    return weight;
}

// 自訂的比較函式，用於 sort
bool compare_weights(const string& a, const string& b) {
    long long weight_a = calculate_weight(a);
    long long weight_b = calculate_weight(b);

    // 規則一：如果體重不同，則體重輕的排前面
    if (weight_a != weight_b) {
        return weight_a < weight_b;
    }
    
    // 規則二：如果體重相同，則按照字典順序排列
    return a < b;
}


class WeightSort
{
public:
    /**
     * @brief 根據「數字體重」對一個字串中的數字進行排序。
     * @param strng 包含用空格分隔的數字的原始字串。
     * @return std::string 排序後的新字串。
     */
    static string orderWeight(const string &strng) {
        // --- 演算法邏輯 ---

        // 1. 使用 stringstream 來拆解輸入的字串。
        //    這可以優雅地處理開頭、結尾或中間的多餘空格。
        stringstream ss(strng);
        string number_str;
        vector<string> numbers;
        while (ss >> number_str) {
            numbers.push_back(number_str);
        }

        // 如果輸入為空或只包含空格，直接回傳空字串
        if (numbers.empty()) {
            return "";
        }

        // 2. 使用 std::sort 搭配我們自訂的比較函式來進行排序。
        sort(numbers.begin(), numbers.end(), compare_weights);

        // 3. 將排序好的數字重新組合成一個字串。
        stringstream result_ss;
        for (size_t i = 0; i < numbers.size(); ++i) {
            result_ss << numbers[i] << (i == numbers.size() - 1 ? "" : " ");
        }
        
        return result_ss.str();
    }
};

/**
 * @brief 一個常規的具名函式，用來執行測試並印出結果。
 * @param input 要測試的字串。
 */
void run_test_weightsort(const string& input) {
    cout << "輸入: \"" << input << "\"" << endl;
    cout << "輸出: \"" << WeightSort::orderWeight(input) << "\"" << endl;
}

// --- 主程式：用來測試 orderWeight 函式 ---
int main() {
    cout << "--- 數字體重排序器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    string test_case = "56 65 74 100 99 68 86 180 90";
    run_test_weightsort(test_case); 
    // 預期輸出: "100 180 90 56 65 74 68 86 99"

    // --- 其他邊界測試 ---
    cout << "\n--- 其他邊界測試 ---\n";
    run_test_weightsort(" 103 123 4444 99 2000 "); // 測試多餘空格
    // 預期輸出: "2000 103 123 99 4444"
    run_test_weightsort(""); // 測試空字串
    // 預期輸出: ""

    cout << "\n測試結束。\n";
    return 0;
}
