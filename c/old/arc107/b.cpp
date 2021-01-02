#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    long long n ,k;
    cin >> n >> k;
    k=abs(k);
    long long s=0;
    int i;
    for(i=2+k;i<=2*n;i++){
        long long t1 = (i-1>n) ? i-1-(i-1-n)*2 :(i-1);
        long long t2 = (i-k-1>n) ? i-k-1-(i-k-1-n)*2 :(i-k-1);
        s+=t1*t2;
    }
    cout << s << endl;
    return 0;
}