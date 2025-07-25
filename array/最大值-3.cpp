#include <iostream>
using namespace std;
int main(){
    int n=5,maxi=0,i;
    int a[5]={2,3,4,5,88};
    for(i=0;i<n;i++){
        if(a[i]>a[maxi]){
            maxi=i;
        }
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<"";
    }
    cout<<endl;
    cout<<"最大值是"<<maxi<<"="<<a[maxi]<<endl;
    return 0;
}