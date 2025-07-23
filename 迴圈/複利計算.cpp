//輸入本金 年利率 年數
//輸出本利和
#include <iostream>
using namespace std;
int main() {
    int y,i;
    double p,r;
    cout << "請輸入本金：";
    cin >> p;
    cout << "請輸入年利率(百分比)：";
    cin >> r;
    cout << "請輸入年數：";
    cin >> y;
    for(i=0;i<y;i++)
    {
        p = p * (1+r / 100); // 計算每年的本利和
    }
    cout << "本利和為：" << p << endl; // 輸出最終的本利和
    // 使用 for 迴圈計算每年的本利和
    return 0;
}