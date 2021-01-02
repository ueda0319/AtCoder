#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int **cs;
    int i,j,c;
    cs = (int**)malloc(sizeof(int *) * (n+1));
    for (i=0;i<=n;i++) {
        cs[i] = (int*)malloc(sizeof(int) * n);
    }
    for (i=0;i<n;i++) {
        cs[0][i] = 0;
    }
    for(i=0;i<n;i++){
        cin >> c;
        memcpy(cs[i+1], cs[i], sizeof(int) * n);
        //for(j=0;j<n;j++){
        //    cs[i+1][j]=cs[i][j];
        //}
        cs[i+1][c-1]++;
    }
    int r,l;
    for(i=0;i<q;i++){
        cin >> l >> r;
        c=0;
        for(j=0;j<n;j++){
            if(cs[r][j]>cs[l-1][j]){
                c++;
            }
        }
        cout << c << endl;
    }
    for (i=0;i<n;i++) {
        free(cs[i]);
    }
    free(cs);
    return 0;
}