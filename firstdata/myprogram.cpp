#include <iostream>

#include <fstream>

#include <cstdlib>
#include <limits>

using namespace std;



int main() {

 ifstream in("data.txt");

if (!in) {

 cout << "input file opening failed\n";

 return 1;
 }


 int sum = 0, value = 0;



while (in >> value) { // 直接在條件中檢查是否成功讀取數字

cout << value << endl;
 sum += value;

}


 in.close(); // 關閉檔案



 cout << "Sum: " << sum << endl; // 顯示總和
cout << "\n程式執行完畢，請按 Enter 鍵結束...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除可能存在的輸入緩衝
    cin.get(); // 等待使用者按下 Enter
return 0;

}