#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 使用二分搜尋法在一個已排序的整數向量中尋找目標值
 * @param sorted_vec 已排序的向量
 * @param target     要尋找的目標整數
 * @return int       如果找到目標，回傳其索引；如果找不到，回傳 -1
 */
int binarySearch(const vector<int>& sorted_vec, int target) {
    int left = 0;
    int right = sorted_vec.size() - 1;

    while (left <= right) {
        // 計算中間索引，(left + right) / 2 在數字極大時可能溢位，這種寫法更安全
        int mid = left + (right - left) / 2;

        if (sorted_vec[mid] == target) {
            // 情況 C：找到了！
            return mid;
        } else if (sorted_vec[mid] < target) {
            // 情況 D：中間值太小，目標在右半邊，排除左半邊
            left = mid + 1;
        } else { // sorted_vec[mid] > target
            // 情況 E：中間值太大，目標在左半邊，排除右半邊
            right = mid - 1;
        }
    }

    // 如果迴圈結束都沒找到，回傳 -1
    return -1;
}

int main() {
    
    vector<int> data = {2, 6, 12, 23, 45, 55, 78, 99};
    int target_number;

    cout << "我們的資料庫裡有 (已排序): ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    cout << "請輸入你想尋找的數字: ";
    cin >> target_number;

    int result_index = binarySearch(data, target_number);

    if (result_index != -1) {
        cout << "找到了！數字 " << target_number << " 位於陣列的索引 " << result_index << "。" << endl;
    } else {
        cout << "很抱歉，在陣列中找不到數字 " << target_number << "。" << endl;
    }

    return 0;
}