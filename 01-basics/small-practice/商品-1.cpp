#include <iostream>
using namespace std;

int main() {
    int wallet, price;

    // 輸入錢包金額與商品價格
    cout << "請輸入錢包內的金額：";
    cin >> wallet;

    cout << "請輸入商品的價格：";
    cin >> price;

    // 確保錢夠買該商品
    if (wallet >= price) {
        int remaining = wallet - price;
        cout << "成功購買！購買後錢包剩餘金額為：" << remaining << " 元。" << endl;
    } else {
        cout << "金額不足，無法購買此商品！" << endl;
    }

    return 0;
}
