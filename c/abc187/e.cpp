#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
vector<int> G[200000];
void dfs(int v, long long *c, int *q, int qi, long long x){
    q[v]=qi;//query id
    c[v]+=x;
    for(int i=0;i<G[v].size();i++){
        if(q[G[v][i]]<qi)dfs(G[v][i],c,q,qi,x);
    }
}
int main(){
    int n;
    cin >> n;
    long long c[n]={0};
    int qi[n]={0};
    int i,j,a,b;
    int as[n],bs[n];
    for(i=0;i<n-1;i++){
        cin >> a >> b;
        a-=1;
        b-=1;
        as[i]=a;
        bs[i]=b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int q;
    cin >> q;
    int t,e;
    long long x;
    for(i=0;i<q;i++){
        cin >> t >> e >> x;
        e-=1;
        if(t==1){
            a=as[e];
            qi[a]=i;
            c[a]+=x;
            for(j=0;j<G[a].size();j++){
                b=bs[e];

                if(G[a][j]==b) continue;
                dfs(G[a][j],c,qi,i,x);

            }
        }else{
            b=bs[e];
            qi[b]=i;
            c[b]+=x;
            for(j=0;j<G[b].size();j++){
                a=as[e];

                if(G[b][j]==a) continue;
                dfs(G[b][j],c,qi,i,x);

            }

        }
    }
    for(i=0;i<n;i++){
        cout << c[i] << endl;
    }
    return 0;
}