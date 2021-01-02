#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int i,j;
    long a[n], b[m];
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<m;i++) cin >> b[i];
    int dp[n+1][m+1];
    for(i=0;i<=n;i++)dp[i][0]=i;
    for(i=0;i<=m;i++)dp[0][i]=i;
    int t1,t2,t3;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            t1=dp[i-1][j]+1;
            t2=dp[i][j-1]+1;
            t3=dp[i-1][j-1]+((a[i-1]==b[j-1]) ? 0:1);
            dp[i][j]=min(min(t1,t2),t3);
        }
    }
    cout << dp[n][m] << endl;
    
    return 0;
}