#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void updateCostP(int n, int *cost, int *tgts, int *exist, int tgt_len){
    int i;
    for(i=0;i<tgt_len;i++){
        if((tgts[i]>n)&&(cost[tgts[i]-1]>cost[tgts[i]]+exist[tgts[i]])){
            tgts[tgt_len]=tgts[i]-1;
            cost[tgts[i]-1]=cost[tgts[i]]+exist[tgts[i]];
            tgt_len++;
        }
        if((tgts[i]<n*n-n)&&(cost[tgts[i]+1]>cost[tgts[i]]+exist[tgts[i]])){
            tgts[tgt_len]=tgts[i]+1;
            cost[tgts[i]+1]=cost[tgts[i]]+exist[tgts[i]];
            tgt_len++;
        }
        if((tgts[i]>n)&&(cost[tgts[i]-n]>cost[tgts[i]]+exist[tgts[i]])){
            tgts[tgt_len]=tgts[i]-n;
            cost[tgts[i]-n]=cost[tgts[i]]+exist[tgts[i]];
            tgt_len++;
        }
        if((tgts[i]<n*n-n)&&(cost[tgts[i]+n]>cost[tgts[i]]+exist[tgts[i]])){
            tgts[tgt_len]=tgts[i]+n;
            cost[tgts[i]+n]=cost[tgts[i]]+exist[tgts[i]];
            tgt_len++;
        }

    }
}
int main(){
    int n;
    cin >> n;
    int cost[n*n],  tgts[n*n], exists[n*n];
    int i,j,k;
    int costzero_len=0,costzero_ofs=0,tgts_len=0;
    int p;

    for(i=0;i<n*n;i++){
        cost[i]=n*n;
        exists[i]=1;
    }
    for(i=0;i<n;i++){
        //上下
        tgts[tgts_len]=i;
        tgts[tgts_len+1]=n*n-n+i;
        cost[i]=0;
        cost[n*n-n+i]=0;
        tgts_len+=2;
    }
    for(i=2;i<n-1;i++){
        //左右
        tgts[tgts_len]=i*n-1;
        tgts[tgts_len+1]=i*n;
        cost[i*n-1]=0;
        cost[i*n]=0;
        tgts_len+=2;
    }
    tgts[tgts_len]=n;
    tgts[tgts_len+1]=n*n-n-1;
    cost[n]=0;
    cost[n*n-n-1]=0;
    tgts_len+=2;

    
    //updateCost(n,cost,costzero,tgts,exists,costzero_len,costzero_ofs);
    updateCostP(n, cost, tgts, exists, tgts_len);
    long ans = 0;
    for(i=0;i<n*n;i++){
        cin >> p;
        p-=1;
        tgts[0]=p;
        tgts_len=1;
        if(cost[p]==0){
            if((p>n)&&(cost[p-1]>0)){
                cost[p-1]=0;
                //costzero[costzero_len]=p-1;
                //costzero_len++;
                tgts[tgts_len]=p-1;
                tgts_len++;
            }
            if((p<n*n-n)&&(cost[p+1]>0)){
                cost[p+1]=0;
                //costzero[costzero_len]=p+1;
                //costzero_len++;
                tgts[tgts_len]=p+1;
                tgts_len++;
            }
            if((p>n)&&(cost[p-n]>0)){
                cost[p-n]=0;
                //costzero[costzero_len]=p-n;
                //costzero_len++;
                tgts[tgts_len]=p-n;
                tgts_len++;
            }
            if((p<n*n-n)&&(cost[p+n]>0)){
                cost[p+n]=0;
                //costzero[costzero_len]=p+n;
                //costzero_len++;
                tgts[tgts_len]=p+n;
                tgts_len++;
            }
        }else{
            //updateCost(n,cost,costzero,tgts,exists,costzero_len,costzero_ofs);
            ans+=cost[p];
        }
        exists[p]=0;
        updateCostP(n, cost, tgts, exists, tgts_len);
    }
    if(n<=2){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}