#include <iostream>
using namespace std;
int main(){
    int n=10,key,i,loc=-1;
    int a[n]={1,5,6,88,66,77,33,12,10};
    cout<<"請輸入一個key值"<<endl;
    cin>>key;
    for(i=0;i<n;i++){
        if(a[i]==key){
            loc=i;
            break;
        }
    }
    if(loc!=-1){
        cout<<"a["<<loc<<"]"<<"="<<key<<endl;

    }
    else{
        cout<<"沒有尋找到"<<key<<endl;
    }
    return 0;

}