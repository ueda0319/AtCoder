#include <bits/stdc++.h>
using namespace std;
int root(int *uf, int *ufc,int k){
    if(uf[k]==k){
        return k;
    }else{
        ufc[uf[k]] += ufc[k];
        ufc[k]=0;
        uf[k]=root(uf,ufc, uf[k]);
        return uf[k];
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    
    int uf[n];
    int ufc[n];
    int i;
    for(i=0;i<n;i++){
        uf[i]=i;
        ufc[i]=1;
    }
    int a,b;
    for(i=0;i<m;i++){
        cin >> a >>b ;
        int ar=root(uf,ufc, a-1);
        int br=root(uf,ufc, b-1);
        if(ar!=br){
            uf[ar]=br;
            ufc[br]+=ufc[ar];
            ufc[ar]=0;
        }
    }
    int count=0;
    for(i=0;i<n;i++){
        if(ufc[i]>count)count=ufc[i];
    }
    cout << count << endl;
    return 0;
}