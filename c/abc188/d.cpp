#include <bits/stdc++.h>
using namespace std;
int main(){
    
    long long n, c;
    cin >> n >> c;
    std::map<long long,long long> de;
    vector<long long> bs;
    int i;
    long long a,b,ci;
    for(i=0;i<n;i++){
        cin >> a >> b >> ci;
        b++;
        de[a] = de[a] + ci;
        de[b] = de[b] - ci;
        bs.push_back(a);
        bs.push_back(b);
    }
    sort(bs.begin(), bs.end());
    long long dt, dc=0;
    long long cost = 0;
    for(i=0;i<n*2-1;i++){
        dt=bs[i+1]-bs[i];
        if(dt==0)continue;
        dc+=de[bs[i]];
        cost += min(dc, c)*dt;
        
    }
    cout << cost << endl;
    return 0;
}