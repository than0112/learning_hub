#include <iostream>
#include <vector>
#include <string>
#include <numeric>   // 引入 accumulate 函式
#include <algorithm> // 引入 adjacent_find 函式

using namespace std;

/**
 * @brief 方法一：數學加總法
 * @details 計算預期總和與實際總和的差值來找出缺失的字母。
 */
char findMissingLetter_sum(const vector<char>& chars) {
    // 1. 計算預期的總和 (一個完整的等差級數)
    // 從第一個字母到最後一個字母，構成一個完整的序列
    long long expected_sum = 0;
    for (char c = chars.front(); c <= chars.back(); c++) {
        expected_sum += c;
    }

    // 2. 計算實際的總和
    // 使用 std::accumulate 函式可以簡潔地完成加總
    long long actual_sum = accumulate(chars.begin(), chars.end(), 0LL);

    // 3. 差值就是缺失字母的 ASCII 碼
    return static_cast<char>(expected_sum - actual_sum);
}

/**
 * @brief 方法二：二元搜尋法
 * @details 利用二分搜尋在 O(log N) 時間內找到缺口。
 */
char findMissingLetter_binary_search(const vector<char>& chars) {
    int left = 0;
    int right = chars.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        // 檢查中間點是否符合預期的連續規律 (chars[i] == chars[0] + i)
        if (chars[mid] == chars[0] + mid) {
            // 如果中間點是正常的，代表缺口在右半邊
            left = mid + 1;
        } else {
            // 如果中間點已經不正常了，代表缺口在左半邊 (包含 mid)
            right = mid;
        }
    }
    
    // 迴圈結束時，left (或 right) 指向缺口之後的第一個元素
    // 缺失的字母就是 chars[0] + left
    return chars[0] + left;
}

/**
 * @brief 方法三：STL 演算法 adjacent_find
 * @details 使用 C++ 標準函式庫的演算法來找到不連續的點。
 */
char findMissingLetter_adjacent_find(const vector<char>& chars) {
    // std::adjacent_find 會尋找第一對滿足條件的相鄰元素
    // 我們的條件是：第二個元素不等於第一個元素加一
    auto it = adjacent_find(chars.begin(), chars.end(), [](char a, char b) {
        return b != a + 1;
    });

    // it 會指向那對不連續元素中的第一個 (例如 'd' in {'d', 'f'})
    // 缺失的字母就是它加一
    return *it + 1;
}


// --- 主程式：用來測試所有進階方法 ---
int main() {
    cout << "--- 尋找消失的字母測試器 (進階技巧) ---\n";

    auto run_all_tests = [](const vector<char>& input) {
        cout << "\n輸入: { ";
        for(size_t i = 0; i < input.size(); ++i) {
            cout << "'" << input[i] << "'";
            if (i < input.size() - 1) cout << ", ";
        }
        cout << " }" << endl;
        cout << "  - 數學加總法: '" << findMissingLetter_sum(input) << "'" << endl;
        cout << "  - 二元搜尋法: '" << findMissingLetter_binary_search(input) << "'" << endl;
        cout << "  - adjacent_find 法: '" << findMissingLetter_adjacent_find(input) << "'" << endl;
    };

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_all_tests({'a','b','c','d','f'}); // 預期輸出: 'e'
    run_all_tests({'O','Q','R','S'});   // 預期輸出: 'P'
    run_all_tests({'X', 'Z'});           // 預期輸出: 'Y'

    cout << "\n測試結束。\n";
    return 0;
}
