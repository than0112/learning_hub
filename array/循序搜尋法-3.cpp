#include <iostream>
#include <vector>
#include <algorithm> // 必須引入 <algorithm> 才能使用 std::find
#include <iterator>  // 為了使用 std::distance

using namespace std;

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

    // --- 核心步驟：呼叫 find ---
    // find 會在 data 的 begin() 到 end() 範圍內，尋找 target_number
    auto goal = find(data.begin(), data.end(), target_number);


    // --- 判斷結果 ---
    // 如果回傳的迭代器不等於 data.end()，代表有找到
    if (goal != data.end()) {
        // 使用 distance 計算從頭到找到的位置，總共有多遠，這就是索引
        int index = distance(data.begin(), goal);
        cout << "找到了！數字 " << target_number << " 位於陣列的索引 " << index << "。" << endl;
    } else {
        // 如果回傳的是 data.end()，代表從頭找到尾都沒找到
        cout << "很抱歉，在陣列中找不到數字 " << target_number << "。" << endl;
    }

    return 0;
}