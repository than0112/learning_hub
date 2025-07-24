/*本題的目標是計算台灣與美國，澳洲，西班牙的時差
使用了C++的標準庫來處理時間和日期，並且使用了簡單的輸入輸出來顯示結果。
*/
#include <iostream>
#include <iomanip> // 引入 iomanip 以使用 setprecision
#include <ctime> // 引入 ctime 以使用時間相關函式
using namespace std;
int main() {
    int h;
    cout << "請輸入台灣時間的時數（0-23）：";
    cin >> h;
    cout<<"美國幾點"<<(h+24-13)%24<<endl;
    cout<<"澳洲幾點"<<(h+24-2)%24<<endl;
    cout<<"西班牙幾點"<<(h+24-7)%24<<endl;

    return 0;
}