#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int root(int *uf, int k){
    if(uf[k]==k){
        return k;
    }else{
        uf[k]=root(uf, uf[k]);
        return uf[k];
    }
}
int main(){
    int n,k;
    cin >> n >> k;
    int a[n][n];
    long long i,j, l;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    bool col_sw[n]={false};
    bool row_sw[n]={false};
    bool sw=false;
    int uf[n];
    for(i=0;i<n;i++) uf[i]=i;
    int col_cnt[n]={0};
    int row_cnt[n]={0};
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            sw=true;
            for(l=0;l<n;l++){
                if(a[i][l]+a[j][l]>k){
                    sw=false;
                    break;
                }
            }
            if(sw){
                int ar=root(uf, i);
                int br=root(uf, j);
                if(ar!=br){
                    uf[ar]=br;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        col_cnt[root(uf,i)]++;
    }

    for(i=0;i<n;i++) uf[i]=i;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            sw=true;
            for(l=0;l<n;l++){
                if(a[l][i]+a[l][j]>k){
                    sw=false;
                    break;
                }
            }
            if(sw){
                int ar=root(uf, i);
                int br=root(uf, j);
                if(ar!=br){
                    uf[ar]=br;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        row_cnt[root(uf,i)]++;
    }
    long long rpattern=1, cpattern=1;
    for(i=0;i<n;i++){
        if(col_cnt[i]<=1)continue;
        for(j=1;j<=col_cnt[i];j++){
            cpattern = (cpattern*j)%998244353;
        }
    }
    for(i=0;i<n;i++){
        if(row_cnt[i]<=1)continue;
        for(j=1;j<=row_cnt[i];j++){
            rpattern = (rpattern*j)%998244353;
        }
    }
    long long pattern = (rpattern*cpattern)%998244353;
    cout <<pattern << endl;
    return 0;
}