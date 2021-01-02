#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    long h[n];
    int best[n] = {0};
    int i;
    int count=n;
    for(i=0;i<n;i++){
        cin >> h[i];
    }
    int a[m], b[m];
    for(i=0;i<m;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        if(h[a[i]] >= h[b[i]]){
            if(best[b[i]]==0){
                best[b[i]] = 1;
                count --;
            }
        }
        if(h[a[i]] <= h[b[i]]){
            if(best[a[i]]==0){
                best[a[i]] = 1;
                count --;
            }
        }
    }cout << count << endl;
    return 0;
}