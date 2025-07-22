//本題是要來計算商店每一天的純利潤 
#include <iostream>
using namespace std;
int main(){
int a;
//等於每一天經營商鋪的金額
cout<<"請輸入每天經營商鋪的金額"<<endl;
cin>>a;
if((200-123)*a-800>0){
    cout<<"每一天的純利潤"<<"="<<(200-123)*a-800<<endl;
}
else{
    cout<<"每一天虧損"<<"="<<abs((200-123)*a-800)<<"元"<<endl;
}
return 0;
}