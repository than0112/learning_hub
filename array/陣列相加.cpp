#include<iostream>
using namespace std;
int main(){
    int n=9;
    int a[n]={1,2,7,3,9,0,8,6,5};
    int b[n]={-2,0,-1,8,-8,0,8,6,5};
    int c[n],i;
    for(i=0;i<=n;i++){
        c[i]=a[i]+b[i];
    }
    cout<<"陣列a和b的結果為";
    for(i=0;i<=n;i++){
        cout<<c[i]<<"";
        cout<<endl;
    }
    return 0;
}