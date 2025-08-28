#include <string>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
string neutralise(const string& s1, const string& s2)
{
   string result="";
   for(size_t i=0; i<s1.length(); i++)
   {
     if(s1[i]==s2[i])
       result+=s1[i];
    else{
        result+='0';
    }
   }
    return result;


}
void run_test(const string& str1, const string& str2) {
    cout << "輸入: (\"" << str1 << "\", \"" << str2 << "\")" << endl;
    cout << "輸出: \"" << neutralise(str1, str2) << "\"" << endl;
}
int main(){
     cout << "\n--- 題目範例測試 ---\n";
    run_test("+-+", "+--");
    run_test("--++--", "++--++");
    run_test("-+-+-+", "-+-+-+");
    run_test("-++-", "-+-+");

    cout << "\n測試結束。\n";

   
    cout << "程式執行完畢，請按 Enter 鍵結束..."<<endl;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 

    return 0;

}