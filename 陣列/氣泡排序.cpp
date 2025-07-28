#include<iostream>
using namespace std;
int main(){
    int n=8,i,j,temp,k;
    int a[n]={2,5,8,7,10,23,1,55};
    for(i=1;i<n;i++){
        for(k=0;k<n;k++){
            cout<<a[k]<<"\t";
        }
        cout<<endl;
    for(j=0;j<n-1;j++){
        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }

    }
    return 0;
}