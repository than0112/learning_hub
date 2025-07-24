#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n, i, j, r, s = 0;
cin >> n;
for (i = 2; i <= n; i++){
    if (n % i == 0){             
        for (j = 2; j <= r; j++){ 
            if (i % j ==0)
            break; 
        }
            if (j > r)
                s = s + i; }
}
cout << s << endl; 
return 0;
}