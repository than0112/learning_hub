#include <iostream>
using namespace std;

int main(){
    int n = 5, minIndex = 0, i; 
    int a[5] = {2, 3, 4, 5, 88};

    // 找出最小值的索引
    for (i = 0; i < n; i++) {
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }

    // 印出原始陣列 (加上空格)
    cout << "陣列內容: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 印出正確的結果
    cout << "最小值是 " << a[minIndex] << "，它位於索引 " << minIndex << endl;
    
    return 0;
}