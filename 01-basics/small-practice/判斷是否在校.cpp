#include <iostream>
using namespace std;
int main(){
int h, m;
cout << "輸入小時與分鐘";
cin >> h >> m;
if ((h > 7 && h < 16) || (h == 7 && m > 49) || (h == 16 && m < 31))
cout << "在校時間";
else
cout << "不是在校時間";
return 0;
}