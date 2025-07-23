//寫一個程式運用關係運算子將59分自動加一分其餘成績不變
//如果成績大於等於60分則不變

#include <iostream>
using namespace std;
int main(){
    int myscore;
    cout<<"請輸入成積"<<endl;
    cin>>myscore;
    //使用關係運算子判斷成績是否小於60分
    if(myscore==59){
        myscore=myscore+=1; //如果成績是59分則加一分
        cout<< "成績加一分後為：" << myscore << endl;
    }
    else if(myscore>=60){
        cout<< "成績不變為：" << myscore << endl; //如果成績大於等於60分則不變
    }
    else{
        cout<< "成績小於59分,恭喜你被當了 歡迎明年再來" << endl; //如果成績小於59分則沒有加分
    }
    return 0;
}
    
