#include <iostream>
using namespace std;
int a;//全域變數
void fun(){
    int b =0;//區域變數b
    static int c=3;//宣告靜態區域變數c
    a+=1;
    b+=1;
    c+=1;
    cout<<"a="<<",b="<<b<<",c="<<c<<endl;
}
int main(){

    for(int i=0;i<3;i++){
        fun();
    }
    return 0;
}