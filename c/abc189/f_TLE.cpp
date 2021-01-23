#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int i,j;
    int a[k];
    for(i=0;i<k;i++)cin >> a[i];

    double p[2][n+1];
    bool ki[n+1];
    for(i=0;i<=n;i++){
        p[0][i]=0;
        p[1][i]=0;
        ki[i]=false;
    }
    p[0][0]=1;
    double ps;
    double as = 0;
    for(i=0;i<k;i++)ki[a[i]]=true;
    for(i=0;i<10000;i++){
        ps=0;
        p[(i+1)%2][0] = 0;
        p[i%2][n] = 0;
        for(j=1;j<=n+m;j++){
            if(j<=n){
                ps+=p[i%2][j-1]/m;
            }
            if(j>=m+1){
                ps-=p[i%2][j-1-m]/m;
            }

            if(j>n){
                p[(i+1)%2][n] += ps;
            }else if(ki[j]){
                p[(i+1)%2][0] += ps;
                p[(i+1)%2][j] =0;
            }else{
                p[(i+1)%2][j] = ps;
            }            
        }
        as += (i+1) * p[(i+1)%2][n];
    }
    if(as<1){
        cout << -1 << endl;
    }else{
        
        cout << as << endl;
    }
    return 0;
}