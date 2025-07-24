#include <iostream> 
using namespace std; 
int main(){
int n, i;
float s = 0;
cin >> n;
for (i = 1; i <= n; i++)
s = s + 1.0 / i;
cout << s;
return 0;
}