//目標能重複輸入一個正整數輸出此數的所有因數
//輸入 一個整數 輸出此整數的所有因數
#include <iostream>
using namespace std;
int main() {
    int x,i;
    while (cin>>x){
        for(i=1;i<=x;i++){
            if(x%i==0){
                cout<<i<<" ";
            }
        }
    }
    return 0;
}
