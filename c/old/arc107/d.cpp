#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    long long a[n+1][2*k+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=2*k;j++)a[i][j]=0;
    }
    for(i=0;i<=n;i++)a[i][1]=1;
    for(i=1;i<n;i++){
        int jmax = min(2*k,n-i);
        for(j=2;j<=jmax;j++){
            a[i+j-1][j]=a[i+j-2][j-1];
            if(j*2<i+j-2) a[i+j-1][j]+=a[i+j-1][j*2];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << a[n][k] << endl;
    return 0;
}