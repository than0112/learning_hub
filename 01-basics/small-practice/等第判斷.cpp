#include <iostream>
using namespace std;
int main(){
    int score;
    cout << "請輸入分數: ";
    cin >> score;
    switch (score)
    {
    case 90 ...100:
        cout<<"優"<<endl;
        break;
    case 80 ...89:
        cout<<"甲"<<endl;
        break;
    case 70 ...79:
        cout<<"乙"<<endl;
        break;
    case 60 ...69:
        cout<<"丙"<<endl;
        break;
    case 0 ...59:
        cout<<"丁"<<endl;
        break;
        
        
    default:
        break;
    }






    return 0;
}