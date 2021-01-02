#include <iostream>
#include <string>
#include <math.h>
#include <bitset>
#include <sstream>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    int c[n];
    int a[n][m];
    int rr[m]={0};
    long min_cost = 0;
    int i,j, k;
    for(i=0;i<n;i++){
        cin >> c[i];
        min_cost+=c[i];
        for(j=0;j<m;j++){
            cin >> a[i][j];
            rr[j]+=a[i][j];
        }
    }
    
    bool flg=true;
    for(i=0;i<m;i++){
        if(rr[i]<x){
            flg=false;
            break;
        }
    }
    if(flg==false){
        cout << -1 << endl;
        return 0;
    }
    int ll=1;

    for(i=0;i<n;i++)ll*=2;
    int lofst = 12-n;
    for(i = 0; i < ll; i++){
        std::stringstream ss;
        ss << std::bitset<12>(i);
        string s = ss.str();
        int r[m]={0};
        long cost = 0;
        for(j = 0; j < n; j++){
            if(s[j+lofst]=='1'){
                cost += c[j];
                for(k=0;k<m;k++){
                    r[k]+=a[j][k];
                    
                }
            }
        }
        flg=true;
        for(j=0;j<m;j++){
            if(r[j]<x){
                flg=false;
                break;
            }
        }
        if(flg && (cost < min_cost)){
            min_cost = cost;
        }
    }
    cout << min_cost << endl;
    return 0;
}