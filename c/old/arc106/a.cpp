#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int nMax = 100;
    long long aa[100];
    long long bb[100];
    aa[0] = 1;
    bb[0] = 1;
    int aa_max = 0;
    while(aa[aa_max]*3 <= 1e18){
        aa_max++;
        aa[aa_max] = aa[aa_max-1]*3;
    }
    int bb_max = 0;
    while(bb[bb_max]*5 <= 1e18){
        bb_max ++;
        bb[bb_max] = bb[bb_max-1]*5;
    }
    long long n;
    cin >> n;
    int i,j;
    for(i=1;i<=aa_max;i++){
        for(j=1;j<=bb_max;j++){
            if(aa[i]+bb[j]==n){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}