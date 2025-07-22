//目標計算梯形面積
#include <iostream>
#include <iomanip> // 引入 iomanip 以使用 setprecision
using namespace std;
int main() {
    double a, b, h;
    
    // 輸入梯形的上底、下底和高
    cout << "請輸入梯形的上底 (a): ";
    cin >> a;
    cout << "請輸入梯形的下底 (b): ";
    cin >> b;
    cout << "請輸入梯形的高 (h): ";
    cin >> h;

    // 計算梯形面積
    double area = ((a + b) / 2) * h;

    // 輸出結果，保留兩位小數
    cout << "梯形的面積是: " << fixed << setprecision(2) << area << endl;

    return 0;
}