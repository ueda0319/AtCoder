#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    x*=100;
    int v,p,asum;
    asum=0;
    int res = -1;
    int i;
    for(i=0;i<n;i++){
        cin >> v >> p;
        if(asum<=x && asum+v*p>x){
            res = i+1;
        }
        asum+=v*p;
    }
    cout << res << endl;
    return 0;
}