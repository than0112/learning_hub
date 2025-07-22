//本題主要是要計算出圓柱體的體積以及表面積
//圓柱體的體積公式=上下底園面積*柱高
//圓柱體的表面積公式=2*上下底園面積+側面積
#include <iostream>
#include <iomanip> // 引入 iomanip 以使用 setprecision
#include <cmath> // 引入 cmath 以使用數學函數
using namespace std;
const double PI = 3.14159; // 定義圓周率常數
int main() {
    double radius, height;
    cout << "請輸入圓柱體的半徑: ";
    cin >> radius;
    cout << "請輸入圓柱體的高度: ";
    cin >> height;

    // 計算體積和表面積
    double volume = PI * radius * radius * height; // 體積公式 V = πr²h
    double surfaceArea = 2 * PI * radius * (radius + height); // 表面積公式 A = 2πr(r + h)

    // 輸出結果
    cout << "圓柱體的體積是: " << fixed << setprecision(2) << volume << " 立方單位" << endl;
    cout << "圓柱體的表面積是: " << fixed << setprecision(2) << surfaceArea << " 平方單位" << endl;

    return 0;
}
