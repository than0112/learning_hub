#include<iostream>
using namespace std;
int main(){
    int n,a[50],c=0;
    while(cout<<"請輸入一個整數n",cin>>n){
    
        while(n>0){
            a[c]=n%2;
            c++;
            n/=2;
        }
        for(int i=c-1;i>=0;i--){
            cout<<a[i];
            cout<<endl;
        }
    }
    return 0;

}