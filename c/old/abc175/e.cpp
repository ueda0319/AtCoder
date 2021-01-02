#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c,k;
    cin >> r >> c >> k;
    int i,j;
    long long **v;
    v = (long long**)malloc(sizeof(long long *) * r);
    for (i=0;i<r;i++) {
        v[i] = (long long*)malloc(sizeof(long long) * c);
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)v[i][j]=0;
    }
    int ri, ci, vi;
    for(i=0;i<k;i++){
        cin >> ri >> ci >> vi;
        v[ri-1][ci-1] = vi;
    }

    long long ki[4][c];
    for(i=0;i<c;i++){
        for(j=0;j<4;j++) ki[j][i]=0;
    }

    for(i=0;i<r;i++){
        ki[1][0]=ki[0][0] + v[i][0];
        ki[2][0]=ki[1][0];
        ki[3][0]=ki[1][0];
        //cout << ki[3][c-1] << endl;
        for(j=1;j<c;j++){
            ki[1][j] = max(max(ki[1][j-1], ki[0][j]), ki[0][j] + v[i][j]);
            ki[2][j] = max(max(ki[2][j-1], ki[1][j]), ki[1][j-1] + v[i][j]);
            ki[3][j] = max(max(ki[3][j-1], ki[2][j]), ki[2][j-1] + v[i][j]);
        }
        for(j=0;j<c;j++){
            ki[0][j] = ki[3][j];
        }
    }
    cout << ki[3][c-1] << endl;
    return 0;
}