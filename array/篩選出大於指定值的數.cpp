#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 原始資料和要比較的值
    vector<int> number_list = {100, 200, 129, 134, 198};
    int value_to_compare = 150;

    cout << "原始數列: ";
    for(int n : number_list) {
        cout << n << " ";
    }
    cout << endl;
    
    cout << "比較值: " << value_to_compare << endl;
    
    cout << "大於 " << value_to_compare << " 的數: ";
    
    // 一個迴圈就搞定！
    for (int num : number_list) {
        // 如果數字大於比較值，就直接印出來
        if (num > value_to_compare) {
            cout << num << " ";
        }
    }
    cout << endl; // 最後換行

    return 0;
}