//小明到商店購物 花了 n元 (<= 1000）、 他拿出一張千元紙鈔 
//,請寫一程式、能輸出最多要找回幾張 500, 100 元紙鈔：幾個 50, 10,5,1 元銅板。
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "請輸入購物金額 (<= 1000): ";
    cin >> n;

    // 計算找零金額
    int change = 1000 - n;

    // 計算各面額的張數
    int five_hundred = change / 500;
    change %= 500;

    int one_hundred = change / 100;
    change %= 100;

    int fifty = change / 50;
    change %= 50;

    int ten = change / 10;
    change %= 10;

    int five = change / 5;
    change %= 5;

    int one = change; // 剩下的就是1元銅板

    // 輸出結果
    cout << "找零金額: " << (1000 - n) << " 元" << endl;
    cout << "500元紙鈔: " << five_hundred << " 張" << endl;
    cout << "100元紙鈔: " << one_hundred << " 張" << endl;
    cout << "50元銅板: " << fifty << " 個" << endl;
    cout << "10元銅板: " << ten << " 個" << endl;
    cout << "5元銅板: " << five << " 個" << endl;
    cout << "1元銅板: " << one << " 個" << endl;

    return 0;
}