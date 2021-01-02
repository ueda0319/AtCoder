#include <iostream>
#include <string>
using namespace std;
int main(){
    long long n, k;
    cin >> n >> k;
    unsigned long long x;
    x = (n>k) ? n-k : k-n;
    if(x>k){
        x = x % k;
    }
    if(x > k-x){
        x=k-x;
    }
    cout << x << endl;
    return 0;
}