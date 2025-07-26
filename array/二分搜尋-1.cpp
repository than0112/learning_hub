#include <iostream>

using namespace std;

int main() {
   
    int sorted_array[] = {2, 6, 12, 23, 45, 55, 78, 99};
    int n = 8; 
    int target;

    cout << "資料庫裡有: 2 6 12 23 45 55 78 99" << endl;
    cout << "------------------------------------" << endl;
    cout << "請輸入你想尋找的數字: ";
    cin >> target;
    cout << endl;

    // 2. 設定搜尋範圍的頭、尾索引
    int left = 0;
    int right = n - 1;
    bool found = false; // 用一個「旗標」來記錄是否找到

    // 3. 核心迴圈：只要搜尋範圍還存在 (left <= right)
    while (left <= right) {
        // 計算中間位置
        int mid = (left + right) / 2;

        // 加上這行來「視覺化」演算法的思考過程
        cout << "正在檢查範圍 [" << left << "..." << right << "] 的中間位置 " << mid << " (數值為 " << sorted_array[mid] << ")" << endl;

        if (sorted_array[mid] == target) {
            // 找到了！
            cout << "\n找到了！數字 " << target << " 位於索引 " << mid << "。" << endl;
            found = true;
            break; // 找到後就可以立刻跳出迴圈
        } 
        else if (sorted_array[mid] < target) {
            // 中間值太小了，代表目標在右半邊 -> 所以我們要捨棄左半邊
            cout << " -> " << sorted_array[mid] << " < " << target << "，往右邊找..." << endl;
            left = mid + 1; // 將搜尋範圍的左邊界移動到 mid 的右邊一格
        } 
        else { // sorted_array[mid] > target
            // 中間值太大了，代表目標在左半邊 -> 所以我們要捨棄右半邊
            cout << " -> " << sorted_array[mid] << " > " << target << "，往左邊找..." << endl;
            right = mid - 1; // 將搜尋範圍的右邊界移動到 mid 的左邊一格
        }
    }

    // 4. 根據旗標判斷最終結果
    // 如果迴圈跑完了，found 旗標仍然是 false，就代表沒找到
    if (!found) {
        cout << "\n在陣列中找不到數字 " << target << "。" << endl;
    }

    return 0;
}