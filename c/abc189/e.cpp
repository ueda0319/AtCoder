#include <bits/stdc++.h>
using namespace std;
void matmul(long long *m1, long long *m2, long long *out){
    out[0]=m1[0]*m2[0] + m1[1]*m2[3];
    out[1]=m1[0]*m2[1] + m1[1]*m2[4];
    out[2]=m1[0]*m2[2] + m1[1]*m2[5] + m1[2];
    out[3]=m1[3]*m2[0] + m1[4]*m2[3];
    out[4]=m1[3]*m2[1] + m1[4]*m2[4];
    out[5]=m1[3]*m2[2] + m1[4]*m2[5] + m1[5];
}
int main(){
    int n;
    cin >> n;
    long long x[n], y[n];
    int i;
    for(i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    int m;
    cin >> m;
    long long mats[m+1][6];
    mats[0][0]=1;
    mats[0][1]=0;
    mats[0][2]=0;
    mats[0][3]=0;
    mats[0][4]=1;
    mats[0][5]=0;
    long long cur_mat[6];
    int op;
    long long p;
    for(i=1;i<=m;i++){
        cin >> op;
        if(op==1){
            cur_mat[0]=0;
            cur_mat[1]=1;
            cur_mat[2]=0;
            cur_mat[3]=-1;
            cur_mat[4]=0;
            cur_mat[5]=0;
        }else if(op==2){
            cur_mat[0]=0;
            cur_mat[1]=-1;
            cur_mat[2]=0;
            cur_mat[3]=1;
            cur_mat[4]=0;
            cur_mat[5]=0;
        }else if(op==3){
            cin >> p;
            cur_mat[0]=-1;
            cur_mat[1]=0;
            cur_mat[2]=2*p;
            cur_mat[3]=0;
            cur_mat[4]=1;
            cur_mat[5]=0;
        }else if(op==4){
            cin >> p;
            cur_mat[0]=1;
            cur_mat[1]=0;
            cur_mat[2]=0;
            cur_mat[3]=0;
            cur_mat[4]=-1;
            cur_mat[5]=2*p;
        }
        matmul(cur_mat, mats[i-1], mats[i]);
    }
    int q, a, b;
    long long xi,yi;
    cin >> q;
    for(i=0;i<q;i++){
        cin >> a >> b;
        b--;
        xi = mats[a][0] * x[b] + mats[a][1] * y[b] + mats[a][2];
        yi = mats[a][3] * x[b] + mats[a][4] * y[b] + mats[a][5];
        cout << xi <<" "<< yi << endl;
    }

    return 0;
}