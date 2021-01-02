#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int root(int *uf, int k){
    if(uf[k]==k){
        return k;
    }else{
        uf[k]=root(uf, uf[k]);
        return uf[k];
    }
}
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> classnames[n];
    int uf[n];
    int i,j, a, b;
    for(i=0;i<n;i++)uf[i]=i;
    for(i=0;i<n;i++){
        cin >> j;
        classnames[j].push_back(i);
    }
    for(i=0;i<q;i++){
        cin >> j >> a >> b;
        if(j==1){
            //mix
            int ar=root(uf, a-1);
            int br=root(uf, b-1);
            if(ar!=br){
                uf[ar]=br;
            }
        }else{
            //output
            int ar = root(uf, a-1);
            int count=0;
            for(j=0;j<classnames[b].size();j++){
                if(root(uf, classnames[b][j])==ar)count++;
            }
            cout <<count << endl;
        }
    }
    
    return 0;
}