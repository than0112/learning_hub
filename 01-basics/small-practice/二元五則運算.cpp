#include <iostream>
using namespace std;
int main(){
    int n1,n2;
    char op;
    cout<<"請輸入兩個整數和一個運算符號(例如: 3 4 +): ";
    cin>>n1>>n2>>op;
    switch(op){
        case '+':
            cout<<n1+n2<<endl;
            break;
        case '-':
            cout<<n1-n2<<endl;
            break;
        case '*':
            cout<<n1*n2<<endl;
            break;
        case '/':
            if(n2!=0){
                cout<<n1/n2<<endl;
            }else{
                cout<<"除數不能為零"<<endl;
            }
            break;
        case '%':
            cout<<n1%n2<<endl;
            break;
        default:
            cout<<"無效的運算符號"<<endl;
    }
    return 0;
}
