//目標判斷月份對應的季節
//輸入月份 輸出季節
#include <iostream>
using namespace std;
int main(){
    int month;
    cout<<"請輸入月份(1-12): ";
    cin>>month;
    switch(month){
        case 3 ...5:
            cout<<"春天"<<endl;
            break;
         case 6 ...8:
            cout<<"夏天"<<endl;
            break;
         case 9 ...11:
            cout<<"秋天"<<endl;
            break;
        case 12:
        case 1 ... 2:
            cout<<"冬天"<<endl;
            break;
            default:
            cout<<"輸入錯誤 請輸入1-12的月份"<<endl;
            break;
        //default: 處理輸入錯誤的情況
        //如果輸入的月份不在1到12之間，則輸出錯誤訊息
            return 0;

    }







    return 0;
}