//依序輸入五個整數 輸出最大值 最小數 以及平均值
//使用後測重複結構
#include <iostream>
#include <climits> // 為了使用 numeric_limits
using namespace std;
int main(){
    int n,count=1,sum=0;
    int Max = INT_MIN; // 初始化最大值為最小整數
    int Min = INT_MAX; // 初始化最小值為最大整數

    do{
        cout << "請輸入第" << count << "個整數：";
        cin >> n;
        // 更新最大值和最小值
        if (n > Max) {
            Max = n;
        }
        if (n < Min) {
            Min = n;
        }

        sum += n; // 累加總和
        count++;  // 計數器增加
    }
    while (count <= 5); // 重複輸入五次
    // 計算平均值
    cout<<"最大值"<< Max << endl;
    cout<<"最小值"<< Min << endl;
    cout<<"平均值"<< sum / 5.0 << endl; // 使用 5.0 來確保平均值是浮點數
    return 0;
}