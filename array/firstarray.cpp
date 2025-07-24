#include <iostream>
using namespace std;

int main() {
    // 宣告一個大小為6的整數陣列來儲存成績
    int scores[6];
    int sum = 0;
    double average;
    
    // 輸入6位數字的成績
    cout << "請輸入6位數字的成績：" << endl;
    for(int i = 0; i < 6; i++) {
        cout << "請輸入第" << i+1 << "位的成績: ";
        cin >> scores[i];
        sum += scores[i]; // 加總成績
    }
    
    
    // 輸出結果
    cout << "成績總和為: " << sum << endl;
    cout << "成績平均為: " << (float)sum/6 << endl;
    
    return 0;
}
