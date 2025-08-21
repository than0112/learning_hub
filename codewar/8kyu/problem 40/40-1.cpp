#include <iostream>
#include <string>
#include <limits> // 用於暫停功能
#include <cctype> 
using namespace std;

string to_alter (string& str) {
    string result="";
    for (char c : str) {
        if(isupper(c)){
            result+=tolower(c);
        } else if(islower(c)){
            result+=toupper(c);
        } else {
            result+=c; 

        }
    }
    return result;
   
}