#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> a;
    int i, an;
    for(i=0;i<n;i++){
        cin >> an;
        a.push_back(an);
    }
    sort(a.begin(), a.end());
    long long ai[n];
    ai[0]=a[0];
    for(i=1;i<n;i++){
        ai[i]=ai[i-1]+a[i];
    }
    long long cost=0;
    for(i=0;i<n-1;i++){
        cost += (ai[n-1]-ai[i]) - (n-1-i)*a[i];
    }
    cout << cost << endl;
    return 0;
}