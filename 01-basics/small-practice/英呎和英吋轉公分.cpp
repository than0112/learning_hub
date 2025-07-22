//本題主要是將英呎以及英吋轉換成公分
//1英呎=12英吋 ，1英吋等於2.54公分
#include <iostream>
using namespace std;
int main() {
    int feet, inches;
    cout << "請輸入英呎數: ";
    cin >> feet;
    cout << "請輸入英吋數: ";
    cin >> inches;

    // 將英呎轉換為公分
    double centimeters = (feet * 12 + inches) * 2.54;

    // 輸出結果
    cout << "轉換後的公分數是: " << centimeters << " cm" << endl;

    return 0;
}