#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int *a = (int *)malloc(sizeof(int)*(n+1));
    int *b = (int *)malloc(sizeof(int)*(m+1));
    int i, j;
    a[0]=0;
    for(i=1;i<=n;i++){
        cin >> a[i];
        a[i] = (a[i-1]>k) ? a[i-1] : a[i-1]+a[i];
    } 
    b[0]=0;
    for(i=1;i<=m;i++){
        cin >> b[i];
        b[i] = (b[i-1]>k) ? b[i-1] : b[i-1]+b[i];
    }
    for(i=0;i<n;i++){
        if(a[i+1]>k)break;
    }
    int bc=i;
    j=0;
    for(;i>=0;i--){
        for(;j<m;j++){
            if(a[i]+b[j+1]>k)break;
        }
        if(i+j>bc){
            bc = i+j;
        }
    }
    cout << bc << endl;
    return 0;
}