#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){
    long long x,k,d;
    cin >> x >> k >> d;
    if(abs(x/d) > k){
        cout << abs(x)-k*d << endl;
    }else{
        int t = abs(x)/d;
        if((k-t)%2==0){
            cout << abs(x)-d*t << endl;
        }else{
            cout << d*(t+1) - abs(x) << endl;
        }
    }
    return 0;
}