#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int i,j,n;
    double ***f;
    f=(double***)malloc(sizeof(double**)*101);
    for(i=0;i<101;i++){
        f[i]=(double**)malloc(sizeof(double*)*101);
        for(j=0;j<101;j++){
            f[i][j]=(double*)malloc(sizeof(double)*101);
        }
    }
    for(i=0;i<=100;i++){
        for(j=0;j<=100;j++){
            f[100][i][j]=0;
            f[i][100][j]=0;
            f[i][j][100]=0;
        }
    }
    for(n=99;n>=0;n--){
        for(i=n;i>=0;i--){
            for(j=n;j>=0;j--){
                f[n][i][j]=(double)n/(n+i+j)*(f[n+1][i][j]+1) + (double)i/(n+i+j)*(f[n][i+1][j]+1) + (double)j/(n+i+j)*(f[n][i][j+1]+1);
                f[i][n][j]=(double)i/(n+i+j)*(f[i+1][n][j]+1) + (double)n/(n+i+j)*(f[i][n+1][j]+1) + (double)j/(n+i+j)*(f[i][n][j+1]+1);
                f[i][j][n]=(double)i/(n+i+j)*(f[i+1][j][n]+1) + (double)j/(n+i+j)*(f[i][j+1][n]+1) + (double)n/(n+i+j)*(f[i][j][n+1]+1);
            }
        }
    }
    int a,b,c;
    cin >> a >> b >> c;
    cout<< fixed << setprecision(10) << f[a][b][c] << endl;
    return 0;
}