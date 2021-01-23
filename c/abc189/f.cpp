#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int i,j;
    int a[k];
    for(i=0;i<k;i++)cin >> a[i];

    double p[n+1],q[n+1];
    bool ki[n+1];
    for(i=0;i<=n;i++){
        p[i]=0;
        q[i]=0;
        ki[i]=false;
    }
    for(i=0;i<k;i++)ki[a[i]]=true;

    double ps=0, qs=0, l=m;
    for(i=n-1;i>=0;i--){
        p[i]=0;
        q[i]=0;
        ps+=p[i+1];
        qs+=q[i+1];
        if(i+m+1<=n){
            ps-=p[i+m+1];
            qs-=q[i+m+1];
        }
        if(ki[i]){
            p[i]=1;
        }else{
            p[i]=ps/m;
            q[i]=qs/m+1.0;
        }
    }
    if(p[0]>=1){
        cout << -1 << endl;
        return 0;
    }
    double f0 = q[0] / (1-p[0]);
    cout<< fixed << setprecision(5) << f0 << endl;
    return 0;
}