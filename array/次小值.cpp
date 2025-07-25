#include <iostream>
#include <vector>
#include <limits> // 為了使用 numeric_limits


using namespace std;

int main() {
    vector<int> numbers = {12, 5, 23, 6, 99, 5, 8};

    if (numbers.size() < 2) {
        cout << "陣列元素少於兩個，無法找到次小值。" << endl;
        return 0;
    }

    // 初始化 smallest 和 second_smallest 為 int 型別能表示的最大值
    int smallest = numeric_limits<int>::max();
    int second_smallest = numeric_limits<int>::max();

    // 遍歷所有選手
    for (int current_number : numbers) {
        if (current_number < smallest) {
            // 發現新的最小值！
            // 原最小值 (smallest) 降級為次小值
            second_smallest = smallest;
            // 新選手成為新最小值
            smallest = current_number;
        } else if (current_number < second_smallest && current_number > smallest) {
            // 比次小值小，但比最小值大
            // 新選手成為新次小值
            second_smallest = current_number;
        }
    }

    // 檢查是否真的找到了次小值
    if (second_smallest == numeric_limits<int>::max()) {
        cout << "沒有找到明確的次小值（可能所有元素都相同）。" << endl;
    } else {
        cout << "陣列中的次小值是: " << second_smallest << endl;
    }
    
    return 0;
}