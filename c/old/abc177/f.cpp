#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    int cost[w]={0};
    int a,b,i, j;
    int mincost=0;
    int ref[w];
    for(i=0;i<w;i++)ref[i]=i;
    for(i=0;i<h;i++){
        cin >> a >>b;
        if(mincost==-1){
            cout << -1 << endl;
            continue;
        }
        a--;
        b--;
        if(a==0){
            for(j=a;j<=b;j++){
                ref[j]=-1;
            }
        }else{
            for(j=b;j>=a;j--){
                if(ref[j]==ref[a-1])break;
                ref[j]=ref[a-1];
            }
        }
        mincost=w+1;
        for(j=0;j<w;j++){
            if(ref[j]==-1)continue;
            cost[j]=j-ref[j];
            if(cost[j]<mincost)mincost=cost[j];
        }
        if(mincost==w+1){
            mincost=-1;
        }else{
            mincost+=i+1;
        }
        cout << mincost << endl;
    }
    return 0;
}