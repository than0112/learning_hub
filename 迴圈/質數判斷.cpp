/*輸入一個整數 若此數是質數 輸出"是質數" 否則輸出"不是整數"*/
//判斷質數的方法
//根號n的計算可以使用sqrt(n)但是需要<cmath>
//解題的方法:使用迴圈 檢查 2~根號n的每個整數是否能整除n 若其中一者可以整除n表示n不是整數跳出迴圈
#include <iostream> 
#include<cmath>
using namespace std;
int main(){
    int n,i,root,prime=1;
    cout<<"請輸入一個整數"<<endl;
    cin>>n;
    root=sqrt(n);
    for(i=2;i<=root;i++){
        if(n%i==0){
            prime=0;
            break;
        }
    }
cout<<n;
prime?cout<<"是質數":cout<<"不是質數";
    return 0;
}

