#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    long n, w;
    cin >> n >> w;
    long *difCost = (long *)malloc(sizeof(long)*200001);
    int i;
    for(i=0;i<=200000;i++){
        difCost[i]=0;
    }
    long s,t,p;
    for(i=0;i<n;i++){
        cin >> s >> t >> p;
        difCost[s]+=p;
        difCost[t]-=p;
    }
    long current_cost=0;
    for(i=0;i<=200000;i++){
        current_cost+=difCost[i];
        if(current_cost>w){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}