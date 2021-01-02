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
    long long as=0;
    vector<long long> bs;
    int i;
    long long ai,bi;
    for(i=0;i<n;i++){
        cin >> ai >> bi;
        as += ai;
        bs.push_back(2*ai+bi);
    }
    sort(bs.begin(), bs.end(), [](long long a, long long b) {
        return a > b;
    });
    for(i=0;i<n;i++){
        if(as<0)break;
        as-=bs[i];
    }
    cout << i << endl;
    return 0;
}