#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long c=0;
    long long i;
    for(i=1;c+i<=n+1;i++){
        c+=i;
    }
    cout << n+2-i << endl;
    return 0;
}