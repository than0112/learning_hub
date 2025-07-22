//計算BMI
//核心思想：BMI = 體重 (kg) / 身高 (m)^2
//輸入體重和身高，計算並輸出BMI值
#include <iostream>
#include <iomanip> // 引入 iomanip 以使用 setprecision
using namespace std;
int main() {
    double weight, height;
    
    // 輸入體重和身高
    cout << "請輸入體重 (kg): ";
    cin >> weight;
    cout << "請輸入身高 (cm): ";
    cin >> height;
    

    // 計算 BMI
    double bmi = weight / (height * height);

    // 輸出結果，保留兩位小數
    cout << "您的 BMI 值是: " << fixed << setprecision(2) << bmi << endl;

    return 0;
}