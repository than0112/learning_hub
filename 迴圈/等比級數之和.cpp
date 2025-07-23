#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double height,total=0;
    cout<<"請輸入高度";
    cin >>height;
    total =height;
    if(height>0.5){
        do{
            height=height/2;
            total += height;
        }while (height>0.5);
        cout<<"總高度為"<<fixed<<setprecision(2)<<total<<"m"<<endl;
    }
    return 0; 
}