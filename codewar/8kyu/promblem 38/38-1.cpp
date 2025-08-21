#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits>    // 用於暫停功能

using namespace std;

int findSmallest(vector<int> list)
{
    // --- 演算法邏輯 ---
    // 使用 C++ 標準函式庫中的 min_element 演算法。
    // 1. min_element 會遍歷指定的範圍 [list.begin(), list.end())。
    // 2. 它會回傳一個「迭代器」(iterator)，指向範圍內最小的那個元素。
    // 3. 我們在前面加上星號 '*' 來「解引用」(dereference) 這個迭代器，
    //    從而取得它所指向的實際數值。
    return *min_element(list.begin(), list.end());
}

void run_test(vector<int> arr) {
    cout << "輸入: { ";
    for(size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    cout << " } -> 輸出: " << findSmallest(arr) << endl;
}

// --- 主程式：用來測試 findSmallest 函式 ---
int main() {
    cout << "--- 尋找最小整數測試器 ---\n";

    // --- 執行題目給的範例測試 ---
    cout << "\n--- 題目範例測試 ---\n";
    run_test({34, 15, 88, 2});
    run_test({34, -345, -1, 100});

    cout << "\n測試結束。\n";

    // --- 暫停程式碼，方便查看結果 ---
    cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.clear(); // 清除可能存在的錯誤狀態
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;
}
