//每一組三個人 依照座號查詢同學分到的組別 例如八號分到第三組
//輸入 座號 輸出組別
#include <iostream>
using namespace std;
int main() {
    int seatNumber;
    cout << "請輸入座號：";
    cin >> seatNumber;

    // 計算組別
    int group = (seatNumber + 2) / 3 ;

    // 輸出結果
    cout << "座號 " << seatNumber << " 分到的組別是：" << group << endl;

    return 0;
}
