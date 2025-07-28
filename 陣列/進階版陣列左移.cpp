#include <iostream>
#include <vector>

using namespace std;

// (同樣使用上面的 printVector 輔助函式)
void printVector(const vector<int>& vec) { 
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl; 
}

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50};

    cout << "原始陣列: ";
    printVector(numbers);

    if (!numbers.empty()) {
        // --- 核心邏輯 ---
        // 1. 先把第一個元素備份起來
        int first_element = numbers.front();

        // 2. 執行簡單左移
        for (size_t i = 0; i < numbers.size() - 1; i++) {
            numbers[i] = numbers[i + 1];
        }

        // 3. 將備份起來的第一個元素，放到陣列的最後
        numbers.back() = first_element;
    }

    cout << "循環左移後: ";
    printVector(numbers);

    return 0;
}