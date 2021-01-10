#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> way[n];
    int i;
    long long a[n];
    long long an;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    int x,y;
    for(i=0;i<m;i++){
        cin >> x >> y;
        way[x-1].push_back(y-1);
    }
    long long valmax=-20000000000;
    long long vals[n];
    for(i=0;i<n;i++)vals[i]=20000000000;
    for(i=0;i<n-1;i++){
        for(int t : way[i]){
            vals[t]=min(a[i], min(vals[i], vals[t]));
            if(a[t]-vals[t]>valmax)valmax=a[t]-vals[t];
        }
    }
    cout << valmax << endl;
    return 0;
}