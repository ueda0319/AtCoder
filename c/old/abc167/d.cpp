#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    long long k;
    cin >> n >> k;
    int a[n], b[n], c[n];
    int i,j;
    for(i=0;i<n;i++){
        cin >> a[i];
        b[i]=-1;
        c[i]=0;
    }
    int ai = 1;
    b[0]=1;
    c[0]=1;
    for(i=1;i<n;i++){
        ai=a[ai-1];
        if(i==k){
            cout << ai << endl;
            return 0;
        }
        if(c[ai-1]==1){
            for(j=0;j<i;j++){
                if(b[j]==ai){
                    int looplen = j-i;
                    int d = (k-i)%looplen;
                    cout << b[j+d] << endl;
                    return 0;
                }
            }
        }else{
            c[ai-1]=1;
        }
        b[i]=ai;

    }
    return 0;
}