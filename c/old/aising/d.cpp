#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int popcount(int n,int x){
    int i, c=0;
    for(i=0;i<n;i++){
        if(1<<i > x)break;
        if(1<<i&x)c++;
    }
    return c;
}
int main(){
    int n;
    string s;
    cin >> n >> s;
    int i;
    int pcs = 0, pc = 0;
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            pcs++;
        }
    }
    
    int vmp[n]={0}, vmm[n]={0};
    vmp[n-1]=1;
    vmm[n-1]=1;
    for(i=2;i<=n;i++){
        vmp[n-i] = (vmp[n-i+1]*2)%(pcs+1);
        if(pcs>1) vmm[n-i] = (vmm[n-i+1]*2)%(pcs-1);
    }
    int snp=0, snm = 0;
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            snp = (snp + vmp[i])%(pcs+1);
            if(pcs>1) snm = (snm + vmm[i])%(pcs-1);
        }
    }
    int sn, sm, c;
    int pct[n+1];
    for(i=0;i<=n;i++)pct[i]=-1;
    pct[1]=1;
    pct[2]=1;
    pct[3]=2;
    pct[4]=1;
    for(i=0;i<n;i++){
        if(s[i]=='0'){
            sn = (snp + vmp[i])%(pcs+1);
        }else if(pcs<=1){
            cout << 0 << endl;
            continue;
        }else{
            sn = (snm - vmm[i]+pcs-1)%(pcs-1);
        }
        c=1;
        while(sn>0){
            if(pct[sn]>0){
                sm = pct[sn];
            }else{
                sm = popcount(n,sn);
                pct[sn]=sm;
            }
            sn = sn % sm;
            c++;
        }
        cout << c << endl;
    }
    return 0;
}