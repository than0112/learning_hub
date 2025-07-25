#include <iostream>
#include <vector>
#include <limits> // 為了使用 numeric_limits

using namespace std;

int main() {
    // 範例陣列，包含重複的最大值
    vector<int> numbers = {12, 45, 23, 6, 99, 78, 99, 55};

    if (numbers.size() < 2) {
        cout << "陣列元素少於兩個，無法找到次大值。" << endl;
        return 0;
    }

    // 初始化冠軍和亞軍
    // numeric_limits<int>::min() 是 int 型別能表示的最小值
    int largest = numeric_limits<int>::min();
    int second_largest = numeric_limits<int>::min();

    // 遍歷所有選手
    for (int current_number : numbers) {
        if (current_number > largest) {
            // 情況 A：發現新的冠軍！
            // 原冠軍 (largest) 降級為亞軍
            second_largest = largest;
            // 新選手成為新冠軍
            largest = current_number;
        } else if (current_number > second_largest && current_number < largest) {
            // 情況 B：比亞軍強，但不如冠軍
            // 新選手成為新亞軍
            second_largest = current_number;
        }
    }

    // 檢查是否真的找到了次大值
    if (second_largest == numeric_limits<int>::min()) {
        cout << "沒有找到明確的次大值（可能所有元素都相同）。" << endl;
    } else {
        cout << "陣列中的次大值是: " << second_largest << endl;
    }
    
    return 0;
}