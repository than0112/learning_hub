#include <iostream>
using namespace std;
int main(){
    int i,n=8,temp;
    int a[]={1,2,4,6,5,9,8,10};
    for(i=0;i<=n-2;i++){
        temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
    }
    for(i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1];
    return 0;
}
  