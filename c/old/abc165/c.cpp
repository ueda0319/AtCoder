#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    int a[q], b[q], c[q],d[q];
    long i, j, k;
    for(i=0; i<q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    int p[n];
    for(i=0;i<n;i++){
        p[i]=1;
    }
    long score_max=0;
    for(i=0;i<10000000000;i++){
        long score=0;
        for(j=0; j<q;j++){
            if(p[b[j]-1] - p[a[j]-1] == c[j]) score += d[j];
        }
        if(score_max<score)score_max=score;
        p[n-1]++;
        for(j=n-1;j>=1;j--){
            if(p[j]>m){
                p[j-1]++;
                for(k=j;k<n;k++){
                    p[k]=p[j-1];
                }
            }
        }
        if(p[0]>m)break;
    }
    cout << score_max << endl;
    return 0;
}