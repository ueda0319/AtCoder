#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int root(int *uf, int k){
    if(uf[k]==k){
        return k;
    }else{
        uf[k]=root(uf, uf[k]);
        return uf[k];
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    long long a[n], b[n];
    int uf[n];
    int i;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    for(i=0;i<n;i++) uf[i]=i;
    for(i=0;i<m;i++){
        int an,bn;
        cin >> an >> bn;
        int ar=root(uf, an-1);
        int br=root(uf, bn-1);
        if(ar!=br){
            uf[ar]=br;
        }
    }
    long long sma[n]={0};
    long long smb[n]={0};
    int id = 0;
    for(i=0;i<n;i++){
        id = root(uf,i);
        sma[id]+=a[i];
        smb[id]+=b[i];
    }
    for(i=0;i<n;i++){
        if(sma[i]!=smb[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}