#include<iostream>
using namespace std;
int maxn(int,int);
float maxn(float,float,float);
int main(){

    cout<<"8,6較大者為"<<maxn(8,6)<<endl;
    cout<<"1.2,2.4,2.9較大者為"<<maxn(1.2,2.4,2.9)<<endl;
    return 0;
}
int maxn(int x,int y){
    return (x>y)?x:y;
}
float maxn(float x,float y,float z){
    float m;
    m = (x>y)?x:y;
    return (z>m)?z:m;
}