/*範例二：計算商店總金額 💰
目標：模擬收銀機，讓使用者可以逐一輸入每樣商品的價格，程式會計算總額，直到使用者輸入 0 代表結帳。

在這裡，0 就是一個合理的標記值，因為正常的商品價格都是正數。
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double price;
    double total = 0.0;

    cout << "請逐一輸入商品價格 (輸入 0 代表結帳):" << endl;

    // 迴圈會一直執行，直到 price 的值為 0
    do {
        cout << "請輸入價格: ";
        cin >> price;

        // 進行輸入驗證
        if (cin.fail()) {
            cout << "輸入無效，請輸入數字。" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            price = -1; // 給定一個非 0 值以繼續迴圈
            continue;
        }

        if (price > 0) {
            total += price;
            cout << "目前總計: " << fixed << setprecision(2) << total << endl;
        }

    } while (price != 0);

    cout << "\n--------------------" << endl;
    cout << "結帳！" << endl;
    cout << "最終總金額為: " << fixed << setprecision(2) << total << " 元" << endl;

    return 0;
}