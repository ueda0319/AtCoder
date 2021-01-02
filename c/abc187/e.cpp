#include <bits/stdc++.h>
using namespace std;
vector<int> G[200000];
// v:頂点番号
// depth:頂点iの深さ
// id:現在の深さ
void dfs_depth(int v, int *depth, int id){
    depth[v]=id;
    for(int i=0;i<G[v].size();i++){
        if(depth[G[v][i]]==0)dfs_depth(G[v][i],depth,id+1);
    }
}
// v:頂点番号
// c:頂点iに書かれている整数
// dc:頂点iでの累積和の変化地
// sc:現在の累積和
void dfs_apply(int v, long long *c, long long *dc, bool *visited, long long sc){
    c[v]=sc+dc[v];
    visited[v]=true;
    for(int i=0;i<G[v].size();i++){
        if(visited[G[v][i]]==false)dfs_apply(G[v][i],c,dc,visited, sc+dc[v]);
    }
}
int main(){
    int n;
    cin >> n;
    long long c[n]={0};
    long long dc[n]={0};//v_iから累積輪がいくら増えるか
    int depth[n]={0};//v_iの深さ

    int i,j,a,b,sab;
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
    //v_0を根に深さを計算
    dfs_depth(0, depth,1);
    int q;
    cin >> q;
    int t,e;
    long long x;
    for(i=0;i<q;i++){
        cin >> t >> e >> x;
        e-=1;
        //根に近い側をaにする
        a=as[e];
        b=bs[e];
        if(depth[a]>depth[b]){
            a=bs[e];
            b=as[e];
            t=(t==1)?2:1;//tを反転
        }
        if(t==1){
            dc[0]+=x;
            dc[b]-=x;
        }else{
            dc[b]+=x;
        }
    }
    bool visited[n]={false};
    dfs_apply(0, c, dc,visited, 0);
    for(i=0;i<n;i++){
        cout << c[i] << endl;
    }
    return 0;
}