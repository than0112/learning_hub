#include <iostream>
#include <vector>
#include <algorithm> // 引入 min_element

int main() {
    std::vector<int> numbers = {12, 45, 23, 6, 99, 78, 55};

    if (numbers.empty()) {
        std::cout << "陣列是空的！" << std::endl;
        return 0;
    }

    // 呼叫 min_element，它會回傳一個指向最小值元素的迭代器
    auto min_iterator = std::min_element(numbers.begin(), numbers.end());

    // 解參考以取得實際數值
    int min_value = *min_iterator;

    std::cout << "陣列中的最小值是: " << min_value << std::endl;
    return 0;
}