#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int tt;
    for(tt=0;tt<t;tt++){
        long long ax,ay,bx,by,cx,cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        int px,py;
        if(ax==bx){
            px=ax;
            py=cy;
        }else if(ax==cx){
            px=ax;
            py=by;
        }else{
            py=ay;
            px=cx;
        }
        int patx=0,paty=0;
        if(ax<px || bx<px || cx<px) patx=-1;
        if(ax>px || bx>px || cx>px) patx=1;
        if(ay<py || by<py || cy<py) paty=-1;
        if(ay>py || by>py || cy>py) paty=1;

        long long cost = 0;
        if(px<0){
            cost += (-px)*2;
            if(patx==-1)cost++;
        }else if(px>0){
            cost += (px)*2;
            if(patx==-1)cost--;
        }
        if(py<0){
            cost += (-py)*2;
            if(paty==-1)cost++;
        }else if(py>0){
            cost += (py)*2;
            if(paty==-1)cost--;
        }
        long long ppa = min(abs(px), abs(py));
        cout << cost << endl;
        if(ppa>1){
            cost -= (ppa-1)*2+1;
        }else if(ppa==1)cost--;
        cout << cost << endl;
        if(ppa>=1){
            if(px*py>0){
                if(px==py)cost++;
            if(patx!=paty)cost--;
            //if(patx==-1 && paty==-1)cost-=1;
            }else{
            //if(patx!=paty)cost-=1;
            if(px*patx>0&&py*paty>0)cost-=(ppa==1) ? 1 :2;
            if(patx==1 && paty==1)cost-=1;
            }
        }
        cout << "step:" << tt << ","  << px << "," << py << "," << patx << "," << paty << endl;
        cout << cost << endl << endl;
    }

    return 0;
}