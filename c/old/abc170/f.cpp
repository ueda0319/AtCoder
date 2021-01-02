#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int h,w,k;
    cin >> h >> w >> k;
    int x1,y1,x2,y2;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--;
    y1--;
    x2--;
    y2--;
    bool c[h*w];
    int pid[h*w];
    int cost[h*w];
    char tt;
    int i,j;
    for(i=0;i<h*w;i++){
        cin >> tt;
        c[i]=(tt=='.') ? true : false;
        cost[i]=-1;
    }
    pid[0]=y1*w+x1;
    cost[y1*w+x1]=0;
    int nc=1;
    int xn,yn,xp,yp;
    for(i=0;i<nc;i++){
        xn=pid[i]%w;
        yn=pid[i]/w;
        for(yp=yn-1;yp>=0&& yn-yp<=k;yp--){
            if(c[yp*w+xn]==false)break;
            if(cost[yp*w+xn]==cost[pid[i]])break;
            if(cost[yp*w+xn]>=0)continue;//check
            pid[nc]=yp*w+xn;
            cost[yp*w+xn]=cost[pid[i]]+1;
            nc++;
            if(x2==xn&&y2==yp){
                cout << cost[pid[i]]+1 << endl;
                return 0;
            }
        }
        for(xp=xn-1;xp>=0&& xn-xp<=k;xp--){
            if(c[yn*w+xp]==false)break;
            if(cost[yn*w+xp]==cost[pid[i]])break;
            if(cost[yn*w+xp]>=0)continue;//check
            pid[nc]=yn*w+xp;
            cost[yn*w+xp]=cost[pid[i]]+1;
            nc++;
            if(x2==xp&&y2==yn){
                cout << cost[pid[i]]+1 << endl;
                return 0;
            }
        }
        for(yp=yn+1;yp<h&& yp-yn<=k;yp++){
            if(c[yp*w+xn]==false)break;
            if(cost[yp*w+xn]==cost[pid[i]])break;
            if(cost[yp*w+xn]>=0)continue;//check
            pid[nc]=yp*w+xn;
            cost[yp*w+xn]=cost[pid[i]]+1;
            nc++;
            if(x2==xn&&y2==yp){
                cout << cost[pid[i]]+1 << endl;
                
                return 0;
            }
        }
        for(xp=xn+1;xp<w&& xp-xn<=k;xp++){
            if(c[yn*w+xp]==false)break;
            if(cost[yn*w+xp]==cost[pid[i]])break;
            if(cost[yn*w+xp]>=0)continue;//check
            pid[nc]=yn*w+xp;
            cost[yn*w+xp]=cost[pid[i]]+1;
            nc++;
            if(x2==xp&&y2==yn){
                cout << cost[pid[i]]+1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}