/*依據答對題數 一到十題 每一題6分
11~20題 每一題2分 前十題每題還是6分
21~40題 每一題1分
40題以上 全部100分
寫一程式能依此規則計分
輸入答對題數
輸出 得分
*/
#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "請輸入答對的題數: ";
    cin >> a;

    

    if (a>=1&&a <= 10) {
        cout<< a * 6<<endl; // 前10題每題6分
    } else if (a>=11 && a <= 20) {
        cout<<10 * 6 + (a - 10) * 2<<endl; // 前10題6分，後10題2分
    } else if (a>=21 && a <= 40) {
        cout<<10 * 6 + 10 * 2 + (a - 20)<<endl; // 前20題計分後，後20題2分
    } else {
        cout<< 100<<endl; // 超過40題，得分為100
    }


    return 0;
}