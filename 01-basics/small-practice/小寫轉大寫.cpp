#include<iostream>
using namespace std;
int main(){
    char ch,letter;
    cout<<"請輸入一個小寫字母"<<endl;
    cin>>ch;
    cout<<"請輸入一個大寫字母"<<endl;
    cin>>letter;
    //將小寫字母轉換為大寫字母
    cout<<"\?轉換後的大寫字母是\?"<<ch-32<<endl;

    if(letter>='A'&& letter<='Z'){
        cout<<"這是大寫字母"<<endl;
    }
    else{
        cout<<"這不是大寫字母"<<endl;
    }
    return 0;
}