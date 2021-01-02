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
    vector<long> a;
    int i,j, an;
    for(i=0;i<n;i++){
        cin >> an;
        a.push_back(an);
    }
    long long cost=0;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++)cost+=abs(a[i]-a[j]);
    }
    //cost += (i-1)*a[n-1] - ai[n-2];
    cout << cost << endl;
    return 0;
}