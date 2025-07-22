#include <iostream>
using   namespace std;
int main(){
    int a,b,c;
    cout<< "請輸入三個整數：" << endl;
    // 輸入三個整數
    // 輸出它們的和、積、絕對差
    cin>>a>>b>>c;
    cout<< a + b + c << endl;
    cout<<a*b*c<<endl;
    cout<<abs(a-b-c)<<endl;


    return 0;
}