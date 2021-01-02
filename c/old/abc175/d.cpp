#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long k;
    cin >> n >> k;
    int p[n];
    long long c[n];
    int i,j;
    for(i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    for(i=0;i<n;i++){
        cin >> c[i];
    }

    long long score[n]={0};
    long long score_d[n];
    for(i=0;i<n;i++)score[i]=-1e-10;
    for(i=0;i<n;i++)score[p[i]]=c[p[i]];
    for(i=1;i<k;i++){
        for(j=0;j<n;j++)score_d[j]=score[j];
        for(j=0;j<n;j++){
            score[p[j]] = max(score_d[p[j]], score_d[j]+c[p[j]]);
        }
    }
    long long score_max = score[0];
    for(i=1;i<n;i++){
        score_max = max(score_max, score[i]);
    }
    cout << score_max << endl;
    return 0;
}