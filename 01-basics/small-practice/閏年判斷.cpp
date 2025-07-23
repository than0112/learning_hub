/*判斷某年是閏年或是平年 閏年的規則是 四年 一閏 逢百不閏 四百再閏  」
 因此判斷的條件是 1. 西元年能被 400 整除 為閏年 
西元年能被 4整除 
但不能被 100 整除 為閏年 。 
閏年外 , 其餘皆為平年 。 
輸入 . 西元年 
輸出 . 閏年或平年*/
#include <iostream>
using namespace std;
int main(){
    int year;
    cout << "請輸入西元年: ";
    cin >> year;
    // 判斷是否為閏年
    if(!(year%400)|| (!(year%4) && (year%100))){
        cout << year << "年是閏年" << endl; // 如果能被400整除 或 能被4整除但不能被100整除則為閏年
    }
    else{
        cout << year << "年是平年" << endl; // 否則為平年
    }
    return 0;
}