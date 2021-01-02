#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
long long gcd(long long a, long long b) {
    if (a < b) return gcd(b, a);  // a >= bに統一する
    
    if (b > 0) {
        return gcd(b, a % b);  // 1つ目のケース
    } else {
        return a;  // 2つ目のケース 終端条件
    }
}
long long extgcd(long long a, long long b, long long& x, long long& y) {

    if (a < b) return extgcd(b, a, y, x);
    // xとyを入れ替え忘れないように注意
    
    if (b > 0) {
        long long g = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return g;
    } else {
        x = 1, y = 0;
        return a;
    }
}
long long mod_inv(long long a, long long m){
    /*if(gcd(a,m)!=1){
        cout << gcd(a,m);
         return -1;
    }*/
    long long x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
int main(){
    int t;
    cin >> t;
    int tc;
    long long nt[t], st[t], kt[t];
    for(tc=0;tc<t;tc++){
        cin >> nt[tc] >> st[tc] >> kt[tc];
    }
    long long n,s,k;
    for(tc=0;tc<t;tc++){
        n=nt[tc];
        s=st[tc];
        k=kt[tc];
        k=k%n;
        if(k==0){
            cout << 1 << endl;
        }
        if((n-s)%k==0){
            cout << (n-s)/k << endl;
            continue;
        }
        long long shift = n % k;
        if(shift==0){
            cout << -1 << endl;
            continue;
        }
        long long d = gcd(s,gcd(n, k));
        n/=d;
        s/=d;
        k/=d;
        if(gcd(n, k)!=1 || n<=1 || s<=1 || k<1){
            cout <<-1 << endl;
            continue;
        }

        long long ainv=mod_inv(n, k);
        if(ainv==-1){
            cout <<-1 << endl;
            continue;
        }
        long long step = ainv * s % k;
        long long res = (step*n-s)/k;//(n-s+(long long)shift*step)/k;
        cout << res << endl;

    }
    return 0;
}