#include <iostream>
#include <string>
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
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    int uf[n];
    int i;
    for(i=0;i<n;i++)uf[i]=i;
    for(i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        int ar=root(uf, a-1);
        int br=root(uf, b-1);
        if(ar!=br){
            uf[ar]=br;
        }
    }
    int count=0;
    for(i=0;i<n;i++){
        if(root(uf,i)==i) count++;
    }
    cout << count-1 << endl;
    return 0;
}