//本題主要練習的部份是要把英里轉換成公里
//英里轉公里的公式是 1 mile = 1.60934 km
//所以我們只要把輸入的英里數乘上1.60934就可以得到公里數
//程式碼中使用了cin來讀取輸入的英里數，然後使用cout來輸出轉換後的公里數
#include <iostream>
using namespace std;
int main() {
    double miles;
    cout << "請輸入英里數: ";
    cin >> miles;

    // 將英里轉換為公里
    double kilometers = miles * 1.60934;

    // 輸出結果
    cout << "轉換後的公里數是: " << kilometers << " km" << endl;

    return 0;
}
