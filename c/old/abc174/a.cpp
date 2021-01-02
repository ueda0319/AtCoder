#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, d;
    cin >> n >> d;
    long long dd = d * d;
    long long p, q;
    int i;
    int count=0;
    for(i=0;i<n;i++){
        cin >> p >> q;
        if(p*p+q*q<=dd){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}