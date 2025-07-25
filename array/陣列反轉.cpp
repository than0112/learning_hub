//使用雙指標交換法
#include <iostream>
#include <vector>
#include <utility> // 為了使用 std::swap

using namespace std;

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50, 60};

    // --- 直接在 main 中印出原始陣列 ---
    cout << "原始陣列: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // --- 核心反轉邏輯 ---
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        swap(numbers[left], numbers[right]);
        left++;
        right--;
    }

    // --- 再次直接在 main 中印出反轉後的陣列 ---
    cout << "反轉陣列: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}