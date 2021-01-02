#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(m==0){
        cout << 1 << endl;
        return 0;
    }
    int sp[m];
    int spc=0;
    int i, a;
    vector<int> al;
    for(i=0;i<m;i++){
        cin >> a;
        al.push_back(a-1);
    }
    sort(al.begin(),al.end());
    sp[0]=al[0];
    if(sp[0]>1){
        spc=sp[0];
    }else{
        spc=n-1-al[m-1];
    }
    for(i=1;i<m;i++){
        sp[i]=al[i]-al[i-1]-1;
        if(spc==0)spc=sp[i];
        if(sp[i]>0)spc=min(spc, sp[i]);
    }
    if(n-1-al[m-1]>0) spc=min(spc, n-1-al[m-1]);
    long t=0;
    for(i=0;i<m;i++){
        if(sp[i]>0){
            t+=ceil(1.0*sp[i]/spc);
        }
    }
    long spl = n-1-al[m-1];
    if(al[m-1]!=n-1) t+=ceil(1.0*spl/spc);//spl-spc+1;
    cout << t << endl;
    return 0;
}