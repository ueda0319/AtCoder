#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int as[n];
    int i;
    for(i=0;i<n;i++){
        cin >> as[i];
    }
    int l,r;
    int nmin;
    int score_max = 0;
    int score;
    for(l=0;l<n;l++){
        nmin = as[l];
        for(r=l;r<n;r++){
            if(nmin>as[r])nmin=as[r];
            score=nmin*(r-l+1);
            if(score>score_max) score_max=score;
        }
    }
    cout  << score_max << endl;
    return 0;
}