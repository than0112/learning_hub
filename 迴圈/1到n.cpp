#include <iostream>
using namespace std;
int main(){
    int n,i=1,s=0;
    cin>>n;
    for(i=1;i<=n;i++){
        if(i%2!=0){
            s=s+i;
        }
        else{
            s=s-i;
        }


    }
    cout<<s<<endl;




    return 0;
}