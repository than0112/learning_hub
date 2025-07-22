#include <iostream>
using   namespace std;
int main(){
    int n;
    cin>>n;
    cout<<"請輸入大於1911的數"<<endl;
    if(n>1911){
        cout<<"民國"<<n-1911<<"年"<<endl;}
     else if(n<1911)
     {
        cout<<"民國前"<<abs(n-1911)<<"年"<<endl;

    }
    else(n==1911);{
        cout<<"民國元年"<<endl;
    }
    return 0;
    
}