//入一個圓的半徑 輸出此圓的面積以及周長
#include <iostream>
#include <iomanip> // 引入 iomanip 以使用 setprecision
#include <cmath> // 引入 cmath 以使用數學函數
using namespace std;
int main() {
    const double PI = 3.14159; // 定義圓周率常數
    double radius;
    cout << "請輸入圓的半徑: ";
    cin >> radius;

    // 計算面積和周長
    double area = PI * radius * radius; // 面積公式 A = πr²
    double circumference = 2 * PI * radius; // 周長公式 C = 2πr

    // 輸出結果
    cout << "圓的面積是: " << fixed << setprecision(2) << area << endl;
    cout << "圓的周長是: " << fixed << setprecision(2) << circumference << endl;

    return 0;
}
