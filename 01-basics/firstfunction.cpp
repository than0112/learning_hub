//For example, a function to return the sum of four parameters can be written as
//求四個整數的總和
//int sum_of_four(int a, int b, int c, int d) {
 //   int sum = 0;
   // sum += a;
    //sum += b;
    //sum += c;
    //sum += d;
    //return sum;
//}
//題目要求

//Input Format
//Input will contain four integers - a b c d  , one per line.

//Output Format
//Return the greatest of the four integers.
//PS: I/O will be automatically handled.
//Sample Input
// 3
// 4
// 6
// 5
// Sample Output
// 6
#include <cstdio>
using namespace std;


    int max_of_four (int a,int b,int c,int d){
        int maxval=a;
        if(b>maxval){
            maxval=b;
        }
        if(c>maxval){
            maxval=c;
        }
        if(d>maxval){
            maxval=d;
        }
        return maxval;
    }
        
        
    

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}