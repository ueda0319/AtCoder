#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    long cost[2][w];
    long cost_top[2][w];
    long cost_left[2][w];
    long cost_lt[2][w];

    int step=0, step_last=1;
    int i, j;
    for(i=0;i<w;i++){
        for(j=0;j<2;j++){
            cost[j][i]=0;
            cost_top[j][i]=0;
            cost_left[j][i]=0;
            cost_lt[j][i]=0;
        }
    }
    //cost_top[1][0]=1;
    string ss;
    for(i=0;i<h;i++){
        cin >> ss;
        
        cost[step][0] = (ss[0]=='.') ? cost_top[step_last][0] : 0;
        if(i==0)cost[step][0]=1;
        cost_top[step][0] = ((ss[0]=='.') ? cost_top[step_last][0] + cost[step][0] : 0) % 1000000007;
        cost_left[step][0] = cost[step][0];
        cost_lt[step][0] = cost[step][0];
        for(j=1;j<w;j++){
            cost[step][j] = ((ss[j]=='.') ? cost_top[step_last][j] + cost_left[step][j-1] + cost_lt[step_last][j-1] : 0 ) % 1000000007;

            cost_top[step][j] = ((ss[j]=='.') ? cost_top[step_last][j] + cost[step][j] : 0) % 1000000007;
            cost_left[step][j] = ((ss[j]=='.') ? cost_left[step][j-1] + cost[step][j] : 0) % 1000000007;
            cost_lt[step][j] = ((ss[j]=='.') ? cost_lt[step_last][j-1] + cost[step][j] : 0) % 1000000007;
        }
        step_last=step;
        step=(step+1)%2;
    }
    cout << cost[step_last][w-1] << endl;
    return 0;
}