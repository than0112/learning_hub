#include <iostream>
#include <vector>

using namespace std;

int sequentialSearch(const vector<int>& vec, int target) {
    // 使用 for 迴圈遍歷 vector 中的每一個元素
    // i 從 0 開始，代表陣列的索引
    for (size_t i = 0; i < vec.size(); ++i) {
        // 比較目前索引 i 的元素是否等於目標值
        if (vec[i] == target) {
            // 如果找到了，立刻回傳當前的索引 i 並結束函式
            return i;
        }
    }

    // 如果整個迴圈都跑完了，代表從頭到尾都沒找到目標
    // 此時回傳 -1 表示「搜尋失敗」
    return -1;
}

int main() {
    vector<int> data = {12, 45, 23, 6, 99, 78, 55};
    int target_number;

    cout << "我們的資料庫裡有: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    cout << "請輸入你想尋找的數字: ";
    cin >> target_number;

    int result_index = sequentialSearch(data, target_number);

    // 根據回傳值判斷結果
    if (result_index != -1) {
        cout << "找到了！數字 " << target_number << " 位於陣列的索引 " << result_index << "。" << endl;
    } else {
        cout << "很抱歉，在陣列中找不到數字 " << target_number << "。" << endl;
    }

    return 0;
}