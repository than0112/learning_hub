#include <iostream>
using namespace std;
#include <iostream>

// 使用 if-else 實現的 abs 函數
double my_abs(double number) {
    // 檢查數字是否為負數
    if (number < 0) {
        // 如果是負數，回傳它的相反數（乘以 -1）
        return -number;
    } else {
        // 如果是正數或零，直接回傳它自己
        return number;
    }
}
void print(){
    cout<<"hello world!"<<endl;
}
void printxyz(int x,int y,int z){
    cout<<"x+y+z"<<" "<<x+y+z<<endl;

}
int add (int a,int b){
    int c;
    c=a+b;
    return c;
}
int main(){
    int x,y,z,r;
    cin>>x>>y>>z;
    r=add(8,6);
    cout<<"相加的結果是"<<"="<<" "<<r;
    cout << "my_abs(15.5)"<<" "<<my_abs(15.5) << endl;
     cout << "my_abs(-20)"<<" "<<my_abs(-20) << endl;
    printxyz(x,y,z);
    print();
    return 0;
}