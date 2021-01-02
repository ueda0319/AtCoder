#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    int a[h][w];
    int amin=101;
    int i,j;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin >> a[i][j];
            if(a[i][j]<amin) amin=a[i][j];
        }
    }
    int cost=0;
    
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(a[i][j]>amin) cost+=a[i][j]-amin;
        }
    }
    cout << cost << endl;
    return 0;
}